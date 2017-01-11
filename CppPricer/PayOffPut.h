#pragma once


#include "PayOff.h"


namespace Pricer {
	namespace Instrument {
		class PayOffPut : public PayOff
		{
		public:
			PayOffPut(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffPut() {};

			virtual PayOffPut* clone() const;

		private:
			double Strike;
		};
	}
}