#pragma once


#include "Cashflow.h"
#include <vector>


namespace Pricer {
	namespace Instrument {

		class PathDependent
		{
		public:
			PathDependent(const std::vector<double>& lookAtTimes);

			virtual unsigned long Cashflows(const std::vector<double>& spotValues, std::vector<Cashflow>& generatedCashflows) const = 0;
			virtual unsigned long MaxNumberOfCashflows() const = 0;
			virtual std::vector<double> PossibleCashflowTimes() const = 0;
			const std::vector<double>& LookAtTimes() const;
			
		private:
			std::vector<double> lookAtTimes;
		};
	}
}