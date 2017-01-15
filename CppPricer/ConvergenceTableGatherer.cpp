#include "stdafx.h"
#include "ConvergenceTableGatherer.h"
#include "NumberOfPathsResult.h"


using namespace std;

namespace Pricer {
	namespace Statistics {
		ConvergenceTableGatherer::ConvergenceTableGatherer(unique_ptr<StatisticsGatherer> inner)
			: inner(move(inner)), stoppingPoint(2), pathsDone(0UL)
		{}


		ConvergenceTableGatherer* ConvergenceTableGatherer::Clone() const
		{
			return new ConvergenceTableGatherer(unique_ptr<StatisticsGatherer>(inner->Clone()));
		}


		void ConvergenceTableGatherer::DumpOneResult(double result)
		{
			inner->DumpOneResult(result);
			pathsDone++;

			if (pathsDone == stoppingPoint)
			{
				stoppingPoint *= 2;
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
			ResultSet currentResults(inner->GetResultsSoFar());
			currentResults.Append(shared_ptr<StatisticResult>(new NumberOfPathsResult(pathsDone)));
			tmp.Append(currentResults);
			return tmp;
		}


		void ConvergenceTableGatherer::Reset()
		{
			stoppingPoint = 2;
			pathsDone = 0UL;
			resultsSoFar = ResultTable();
		}
	}
}