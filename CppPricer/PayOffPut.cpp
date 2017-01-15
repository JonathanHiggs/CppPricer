#include "stdafx.h"
#include "PayOffPut.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {
		PayOffPut::PayOffPut(double strike)
			: Strike(strike)
		{}


		double PayOffPut::operator()(double spot) const
		{
			return max(Strike - spot, 0.0);
		}


		PayOffPut* PayOffPut::Clone() const
		{
			return new PayOffPut(Strike);
		}
	}
}