#include "stdafx.h"
#include "BlackScholes.h"
#include "BlackScholesCall.h"


namespace Pricer {
	namespace Models {

		BlackScholesCall::BlackScholesCall(double discount, double drift, double timeToExpiry, double spot, double strike)
			: discount(discount), drift(drift), timeToExpiry(timeToExpiry), spot(spot), strike(strike)
		{ }


		double BlackScholesCall::Price(double vol) const
		{
			return BlackScholes::Call(spot, strike, drift, discount, vol, timeToExpiry);
		}


		double BlackScholesCall::Vega(double vol) const
		{
			return BlackScholes::CallVega(spot, strike, drift, discount, vol, timeToExpiry);
		}
	}
}