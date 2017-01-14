#include "stdafx.h"
#include "Option.h"


using namespace std;


namespace Pricer {
	namespace Instrument {
		VanillaOption::VanillaOption(unique_ptr<PayOff> payOff, double expiry)
			: expiry(expiry), payOff(move(payOff))
		{
		}


		double VanillaOption::GetExpiry() const
		{
			return expiry;
		}


		double VanillaOption::OptionPayOff(double spot) const
		{
			return (*payOff)(spot);
		}
	}
}