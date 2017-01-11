#pragma once


#include "PayOff.h"
#include <memory>


namespace Pricer {
	namespace Instrument {
		class VanillaOption
		{
		public:
			VanillaOption(PayOff* payOff, double expiry);
			double GetExpiry() const;
			double OptionPayOff(double spot) const;

		private:
			std::unique_ptr<PayOff> payOff;
			double expiry;
		};
	}
}