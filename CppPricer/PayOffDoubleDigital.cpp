#include "stdafx.h"
#include "PayOffDoubleDigital.h"
#include <minmax.h>


namespace Pricer {
	namespace Instrument {
		PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel, double upperLevel)
			: LowerLevel(lowerLevel), UpperLevel(upperLevel)
		{}


		double PayOffDoubleDigital::operator()(double spot) const
		{
			return LowerLevel < spot && spot < UpperLevel ? 1.0 : 0.0;
		}


		PayOffDoubleDigital* PayOffDoubleDigital::Clone() const
		{
			return new PayOffDoubleDigital(LowerLevel, UpperLevel);
		}
	}
}