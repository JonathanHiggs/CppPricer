#pragma once


#include "PathDependent.h"
#include "PayOff.h"


namespace Pricer {
	namespace Instrument {

		class PathDepenentAsian : public PathDependent
		{
		public:
			PathDepenentAsian(const std::vector<double> lookAtTimes, double deliveryTime, std::unique_ptr<PayOff> payOff);

			virtual unsigned long Cashflows(const std::vector<double>& spotValues, std::vector<Cashflow>& generatedCashflows) const;
			virtual PathDepenentAsian* Clone() const;
			virtual unsigned long MaxNumberOfCashflows() const;
			virtual std::vector<double> PossibleCashflowTimes() const;

			virtual ~PathDepenentAsian() {};

		private:
			double deliveryTime;
			std::unique_ptr<PayOff> payOff;
			unsigned long numberOfTimes;
		};
	}
}