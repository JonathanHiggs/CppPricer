#include "stdafx.h"
#include "PayOffDigitalPut.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {

		PayOffDigitalPut::PayOffDigitalPut(double strike)
			: Strike(strike)
		{}


		double PayOffDigitalPut::operator()(double spot) const
		{
			return Strike > spot ? 1.0 : 0.0;
		}


		PayOffDigitalPut* PayOffDigitalPut::Clone() const
		{
			return new PayOffDigitalPut(Strike);
		}
	}
}