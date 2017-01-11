#pragma once


#include "StatisticsResult.h"


namespace Pricer {
	namespace Statistics {
		class MeanResult : public StatisticResult
		{
		public:
			MeanResult(double mean);

			virtual void Serialize(std::ostream& os) const;

		private:
			double mean;
		};
	}
}