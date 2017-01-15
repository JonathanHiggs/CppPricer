#pragma once


#include "StatisticsResult.h"


namespace Pricer {
	namespace Statistics {

		class NumberOfPathsResult : public StatisticResult
		{
		public:
			NumberOfPathsResult(int numberOfPaths);

			virtual void Serialize(std::ostream& os) const { os << numberOfPaths; };

		private:
			int numberOfPaths;
		};
	}
}