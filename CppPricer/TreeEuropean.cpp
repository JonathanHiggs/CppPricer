#include "stdafx.h"
#include "TreeEuropean.h"
#include <minmax.h>


using namespace std;


namespace Pricer {
	namespace Instrument {

		TreeEuropean::TreeEuropean(double finalTime, unique_ptr<PayOff> payOff)
			: TreeInstrument(finalTime), payOff(move(payOff))
		{}


		TreeEuropean* TreeEuropean::Clone() const
		{
			return new TreeEuropean(GetFinalTime(), unique_ptr<PayOff>(payOff->Clone()));
		}


		double TreeEuropean::FinalPayOff(double spot) const
		{
			return (*payOff)(spot);
		}


		double TreeEuropean::PreFinalValue(double spot, double time, double discountedFutureValue) const
		{
			return discountedFutureValue;
		}
	}
}