#pragma once


#include "PayOff.h"


namespace Pricer {
	namespace Instrument {
		class PayOffCall : public PayOff
		{
		public:
			PayOffCall(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffCall() {};

			virtual PayOffCall* clone() const;

		private:
			double strike;
		};
	}
}