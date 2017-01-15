#include "stdafx.h"
#include "ConvergenceTableGatherer.h"
#include "NumberOfPathsResult.h"


using namespace std;

namespace Pricer {
	namespace Statistics {
		ConvergenceTableGatherer::ConvergenceTableGatherer(unique_ptr<StatisticsGatherer> inner, unsigned long recordStride)
			: inner(move(inner)), stoppingPoint(recordStride), pathsDone(0UL), recordStride(recordStride)
		{}


		ConvergenceTableGatherer* ConvergenceTableGatherer::Clone() const
		{
			return new ConvergenceTableGatherer(unique_ptr<StatisticsGatherer>(inner->Clone()), recordStride);
		}


		void ConvergenceTableGatherer::DumpOneResult(double result)
		{
			inner->DumpOneResult(result);
			pathsDone++;

			if (pathsDone == stoppingPoint)
			{
				stoppingPoint += recordStride;
				ResultSet thisResult(inner->GetResultsSoFar());
				thisResult.Append(shared_ptr<StatisticResult>(new NumberOfPathsResult(pathsDone)));
				resultsSoFar.Append(thisResult);
			}
		}


		ResultSet ConvergenceTableGatherer::GetResultsSoFar() const
		{
			return inner->GetResultsSoFar();
		}


		ResultTable ConvergenceTableGatherer::GetResultTable() const
		{
			ResultTable tmp(resultsSoFar);
			if (pathsDone != stoppingPoint - recordStride)
			{
				ResultSet currentResults(inner->GetResultsSoFar());
				currentResults.Append(shared_ptr<StatisticResult>(new NumberOfPathsResult(pathsDone)));
				tmp.Append(currentResults);
			}
			return tmp;
		}


		void ConvergenceTableGatherer::Reset()
		{
			stoppingPoint = recordStride;
			pathsDone = 0UL;
			resultsSoFar = ResultTable();
		}
	}
}