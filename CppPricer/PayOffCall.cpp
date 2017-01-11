#include "stdafx.h"
#include "PayOffCall.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {
		PayOffCall::PayOffCall(double strike)
			: strike(strike)
		{}


		double PayOffCall::operator()(double spot) const
		{
			return max(spot - strike, 0.0);
		}


		PayOffCall* PayOffCall::clone() const
		{
			return new PayOffCall(strike);
		}
	}
}