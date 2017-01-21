#pragma once


#include "PayOff.h"
#include "TreeInstrument.h"
#include <memory>


namespace Pricer {
	namespace Instrument {

		class TreeEuropean : public TreeInstrument
		{
		public:
			TreeEuropean(double finalTime, std::unique_ptr<PayOff>& payOff);

			virtual TreeEuropean* Clone() const;
			virtual double FinalPayOff(double spot) const;
			virtual double PreFinalValue(double spot, double time, double discountedFutureValue) const;

			virtual ~TreeEuropean() {};

		private:
			std::unique_ptr<PayOff> payOff;
		};
	}
}