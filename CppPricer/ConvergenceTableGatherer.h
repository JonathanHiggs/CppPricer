#pragma once

#include "stdafx.h"
#include "StatisticsGatherer.h"
#include "ResultTable.h"
#include <vector>


namespace Pricer {
	namespace Statistics {
		class ConvergenceTableGatherer : public StatisticsGatherer
		{
		public:
			ConvergenceTableGatherer(std::unique_ptr<StatisticsGatherer> inner, unsigned long recordStride);

			virtual ConvergenceTableGatherer* Clone() const;
			virtual void DumpOneResult(double result);
			virtual ResultSet GetResultsSoFar() const;
			virtual void Reset();
			ResultTable GetResultTable() const;

		private:
			std::unique_ptr<StatisticsGatherer> inner;
			ResultTable resultsSoFar;
			unsigned long stoppingPoint;
			unsigned long recordStride;
			unsigned long pathsDone;
		};
	}
}