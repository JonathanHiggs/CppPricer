#include "stdafx.h"
#include "BinomialTree.h"


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;


namespace Pricer {
	namespace Tree {

		BinomialTree::BinomialTree(
			double spot,
			unique_ptr<Parameter>& r,
			unique_ptr<Parameter>& d,
			double volatility,
			unsigned long steps,
			double time
		)
			: spot(spot), r(move(r)), d(move(d)), volatility(volatility), steps(steps), time(time), treeBuilt(false)
		{ }


		void BinomialTree::BuildTree()
		{
			tree.resize(steps + 1);

			double initialLogSpot = log(spot), thisTime;

			for (unsigned long i = 0; i <= steps; i++)
			{
				tree[i].resize(i + 1);
				thisTime = (i * time) / steps;

				double movedLogSpot = initialLogSpot 
					+ r->Integral(0.0, thisTime) 
					- d->Integral(0.0, thisTime)
					- 0.5 * volatility * volatility * thisTime;

				double standardDeviation = volatility * sqrt(time / steps);

				for (long j = -static_cast<long>(i), k = 0; j <= static_cast<long>(i); j = j + 2, k++)
					tree[i][k].first = exp(movedLogSpot + j * standardDeviation);
			}

			for (unsigned long l = 0; l < steps; l++)
				discounts[l] = exp(-r->Integral(l * time / steps, (l + 1) * time / steps));

			treeBuilt = true;
		}


		double BinomialTree::Price(shared_ptr<TreeInstrument>& option)
		{
			if (!treeBuilt)
				BuildTree();

			if (option->GetFinalTime() != time)
				throw("Mismatched instrument in BinomialTree");

			for (long j = -static_cast<long>(steps), k = 0; j <= static_cast<long>(steps); j = j + 2, k++)
				tree[steps][k].second = option->FinalPayOff(tree[steps][k].first);

			for (unsigned long i = 1; i < steps; i++)
			{
				unsigned long index = steps - i;
				double thisTime = index * time / steps;

				for (long j = -static_cast<long>(index), k = 0; j <= static_cast<long>(index); j = j + 2, k++)
				{
					double spot = tree[index][k].first;
					double futureDiscountedValue = 
						0.5 
						* discounts[index] 
						* (tree[index + 1][k].second + tree[index + 1][k + 1].second);

					tree[index][k].second = option->PreFinalValue(spot, thisTime, futureDiscountedValue);
				}
			}

			return tree[0][0].second;
		}
	}
}