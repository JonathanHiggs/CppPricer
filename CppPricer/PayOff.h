#pragma once


#include <memory>


namespace Pricer {
	namespace Instrument {

		class PayOff
		{
		public:
			PayOff() {};
			virtual double operator()(double spot) const = 0;
			virtual ~PayOff() {};

			virtual PayOff* Clone() const = 0;
		};
	}
}