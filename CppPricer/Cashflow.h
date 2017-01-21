#pragma once


#include <vector>


namespace Pricer {
	namespace Instrument {

		class Cashflow {
		public:
			Cashflow(unsigned long timeIndex = 0UL, double amount = 0.0)
				: TimeIndex(timeIndex), Amount(amount) {};

			double Amount;
			unsigned long TimeIndex;
		};
	}
}