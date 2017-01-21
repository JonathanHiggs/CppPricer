#include "stdafx.h"
#include "ExoticEngine.h"


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;
using namespace Pricer::Statistics;


namespace Pricer {
	namespace Service {

		ExoticEngine::ExoticEngine(unique_ptr<PathDependent>& product, shared_ptr<Parameter> r)
			: product(move(product)), r(r), discounts(this->product->PossibleCashflowTimes().size())
		{
			auto possibleCashflowTimes = this->product->PossibleCashflowTimes();

			for (unsigned long i = 0; i < discounts.size(); i++)
				discounts[i] = exp(-r->Integral(0.0, possibleCashflowTimes[i]));

			theseCashflows.resize(this->product->MaxNumberOfCashflows());
		}


		double ExoticEngine::DoOnePath(const vector<double> spotValues) const
		{
			unsigned long numberOfCashflows = product->Cashflows(spotValues, theseCashflows);

			double value = 0.0;

			for (unsigned long i = 0; i < numberOfCashflows; i++)
				value += theseCashflows[i].Amount * discounts[theseCashflows[i].TimeIndex];

			return value;
		}


		void ExoticEngine::Run(StatisticsGatherer& gatherer, unsigned long numberOfPaths)
		{
			vector<double> spotValues(product->LookAtTimes().size());

			theseCashflows.resize(product->MaxNumberOfCashflows());
			double thisValue;

			for (unsigned long i = 0; i < numberOfPaths; i++)
			{
				GetOnePath(spotValues);
				thisValue = DoOnePath(spotValues);
				gatherer.DumpOneResult(thisValue);
			}
		}


		const unique_ptr<PathDependent>& ExoticEngine::Product() const
		{
			return this->product;
		}
	}
}