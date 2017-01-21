#pragma once


#include "PayOff.h"
#include <memory>


namespace Pricer {
	namespace Instrument {

		class VanillaOption
		{
		public:
			VanillaOption(std::unique_ptr<PayOff> payOff, double expiry);
			double GetExpiry() const;
			double GetPayOff(double spot) const;

		private:
			std::unique_ptr<PayOff> payOff;
			double expiry;
		};
	}
}