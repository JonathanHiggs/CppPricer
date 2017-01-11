#pragma once


#include "StatisticsGatherer.h"


namespace Pricer {
	namespace Statistics {
		class MeanGatherer : public StatisticsGatherer
		{
		public:
			MeanGatherer();
			virtual std::unique_ptr<StatisticsGatherer> clone() const;

			virtual void DumpOneResult(double result);
			virtual ResultSet GetResultsSoFar() const;
			virtual void Reset();

		private:
			double runningSum;
			unsigned long pathsDone;
		};
	}
}