#include "stdafx.h"
#include "PayOffDigitalCall.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {
		PayOffDigitalCall::PayOffDigitalCall(double strike)
			: Strike(strike)
		{}


		double PayOffDigitalCall::operator()(double spot) const
		{
			return spot > Strike ? 1.0 : 0.0;
		}


		PayOffDigitalCall* PayOffDigitalCall::clone() const
		{
			return new PayOffDigitalCall(Strike);
		}
	}
}