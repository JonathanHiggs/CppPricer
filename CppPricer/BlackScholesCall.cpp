#include "stdafx.h"
#include "BlackScholes.h"
#include "BlackScholesCall.h"


namespace Pricer {
	namespace Models {

		BlackScholesCall::BlackScholesCall(double discount, double drift, double timeToExpiry, double spot, double strike)
			: discount(discount), drift(drift), timeToExpiry(timeToExpiry), spot(spot), strike(strike)
		{ }


		double BlackScholesCall::operator()(double vol) const
		{
			return BlackScholes::Call(spot, strike, drift, discount, vol, timeToExpiry);
		}
	}
}