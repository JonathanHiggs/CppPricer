#include "stdafx.h"
#include "Option.h"


using namespace std;


namespace Pricer {
	namespace Instrument {
		Option::Option(unique_ptr<PayOff> payOff, double expiry)
			: expiry(expiry), payOff(move(payOff))
		{
		}


		double Option::GetExpiry() const
		{
			return expiry;
		}


		double Option::OptionPayOff(double spot) const
		{
			return (*payOff)(spot);
		}
	}
}