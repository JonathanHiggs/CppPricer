#include "stdafx.h"
#include "PayOffDigitalCall.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {

		PayOffDigitalCall::PayOffDigitalCall(double strike)
			: strike(strike)
		{}


		double PayOffDigitalCall::operator()(double spot) const
		{
			return spot > strike ? 1.0 : 0.0;
		}


		PayOffDigitalCall* PayOffDigitalCall::Clone() const
		{
			return new PayOffDigitalCall(strike);
		}
	}
}