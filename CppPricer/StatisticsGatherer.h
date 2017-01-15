#pragma once


#include "StatisticsResult.h"
#include "ResultSet.h"
#include <memory>
#include <vector>


namespace Pricer {
	namespace Statistics {

		class StatisticsGatherer
		{
		public:
			StatisticsGatherer() {};
			virtual StatisticsGatherer* Clone() const = 0;
			virtual ~StatisticsGatherer() {};

			virtual void DumpOneResult(double result) = 0;
			virtual ResultSet GetResultsSoFar() const = 0;
			virtual void Reset() = 0;
		};
	}
}