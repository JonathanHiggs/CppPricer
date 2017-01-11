#include "stdafx.h"
#include "Option.h"


using namespace std;


namespace Pricer {
	namespace Instrument {
		VanillaOption::VanillaOption(PayOff* payOff, double expiry)
			: expiry(expiry)
		{
			this->payOff = std::unique_ptr<PayOff>(payOff);
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