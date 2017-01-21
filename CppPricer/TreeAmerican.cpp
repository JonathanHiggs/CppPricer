#include "stdafx.h"
#include "TreeAmerican.h"
#include <minmax.h>


using namespace std;


namespace Pricer {
	namespace Instrument {

		TreeAmerican::TreeAmerican(double finalTime, std::unique_ptr<PayOff> payOff)
			: TreeInstrument(finalTime), payOff(move(payOff))
		{}


		TreeAmerican* TreeAmerican::Clone() const
		{
			return new TreeAmerican(GetFinalTime(), unique_ptr<PayOff>(payOff->Clone()));
		}


		double TreeAmerican::FinalPayOff(double spot) const
		{
			return (*payOff)(spot);
		}


		double TreeAmerican::PreFinalValue(double spot, double time, double discountedFutureValue) const
		{
			return max((*payOff)(spot), discountedFutureValue);
		}
	}
}