#pragma once


#include "PayOff.h"
#include <memory>


namespace Pricer {
	namespace Instrument {
		class Option
		{
		public:
			Option(std::unique_ptr<PayOff> payOff, double expiry);
			double GetExpiry() const;
			double OptionPayOff(double spot) const;

		private:
			std::unique_ptr<PayOff> payOff;
			double expiry;
		};
	}
}