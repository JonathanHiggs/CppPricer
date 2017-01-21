#pragma once


#include "PayOff.h"
#include "TreeInstrument.h"
#include <memory>


namespace Pricer {
	namespace Instrument {

		class TreeAmerican : public TreeInstrument
		{
		public:
			TreeAmerican(double finalTime, std::unique_ptr<PayOff>& payOff);

			virtual TreeAmerican* Clone() const;
			virtual double FinalPayOff(double spot) const;
			virtual double PreFinalValue(double spot, double time, double discountedFutureValue) const;

			virtual ~TreeAmerican() {};

		private:
			std::unique_ptr<PayOff> payOff;
		};
	}
}
