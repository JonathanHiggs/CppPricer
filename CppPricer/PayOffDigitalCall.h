#pragma once


#include "PayOff.h"


namespace Pricer {
	namespace Instrument {
		class PayOffDigitalCall : public PayOff
		{
		public:
			PayOffDigitalCall(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffDigitalCall() {};

			virtual PayOffDigitalCall* clone() const;

		private:
			double Strike;
		};
	}
}