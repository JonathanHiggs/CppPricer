#pragma once


#include "PayOff.h"


namespace Pricer {
	namespace Instrument {
		class PayOffDoubleDigital : public PayOff
		{
		public:
			PayOffDoubleDigital(double lowerLevel, double upperLevel);
			virtual double operator() (double spot) const;
			virtual ~PayOffDoubleDigital() {};

			virtual PayOffDoubleDigital* clone() const;

		private:
			double LowerLevel;
			double UpperLevel;
		};
	}
}