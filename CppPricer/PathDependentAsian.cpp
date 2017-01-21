#include "stdafx.h"
#include "PathDependentAsian.h"
#include <numeric>


using namespace std;


namespace Pricer {
	namespace Instrument {

		PathDepenentAsian::PathDepenentAsian(
			const vector<double> lookAtTimes,
			double deliveryTime,
			unique_ptr<PayOff> payOff
		)
			: PathDependent(lookAtTimes), deliveryTime(deliveryTime), payOff(move(payOff)), numberOfTimes(lookAtTimes.size())
		{}


		unsigned long PathDepenentAsian::Cashflows(const vector<double>& spotValues, vector<Cashflow>& generatedCashflows) const
		{
			double sum = std::accumulate(spotValues.begin(), spotValues.end(), 0.0);
			double mean = sum / numberOfTimes;

			generatedCashflows[0].TimeIndex = 0UL;
			generatedCashflows[0].Amount = (*payOff)(mean);

			return 1UL;
		}


		PathDepenentAsian* PathDepenentAsian::Clone() const
		{
			return new PathDepenentAsian(LookAtTimes(), deliveryTime, unique_ptr<PayOff>(payOff->Clone()));
		}


		unsigned long PathDepenentAsian::MaxNumberOfCashflows() const
		{
			return 1UL;
		}


		vector<double> PathDepenentAsian::PossibleCashflowTimes() const
		{
			vector<double> temp(1);
			temp[0] = deliveryTime;
			return temp;
		}
	}
}