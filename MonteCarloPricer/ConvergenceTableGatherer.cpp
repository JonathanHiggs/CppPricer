#include "stdafx.h"
#include "ConvergenceTableGatherer.h"


using namespace std;


ConvergenceTableGatherer::ConvergenceTableGatherer(StatisticsGatherer& inner)
	: inner(inner.clone()), stoppingPoint(2), pathsDone(0UL)
{}


ConvergenceTableGatherer::ConvergenceTableGatherer(StatisticsGatherer* inner)
	: inner(inner), stoppingPoint(2), pathsDone(0UL)
{}


ConvergenceTableGatherer::ConvergenceTableGatherer(unique_ptr<StatisticsGatherer> inner)
	: inner(move(inner)), stoppingPoint(2), pathsDone(0UL)
{}


void ConvergenceTableGatherer::DumpOneResult(double result)
{
	inner->DumpOneResult(result);
	pathsDone++;

	if (pathsDone == stoppingPoint)
	{
		stoppingPoint *= 2;
		vector<StatisticResult*> thisResult(inner->GetResultsSoFar());
		resultsSoFar.push_back(thisResult);
	}
}


vector<vector<StatisticResult*>> ConvergenceTableGatherer::GetResultsSoFar() const
{
	vector<vector<StatisticResult*>> tmp(resultsSoFar);

	if (pathsDone * 2 != stoppingPoint)
	{
		vector<StatisticResult*> thisResult(inner->GetResultsSoFar());
		tmp.push_back(thisResult);
	}

	return tmp;
}


unique_ptr<ConvergenceTableGatherer> ConvergenceTableGatherer::clone() const
{
	return unique_ptr<ConvergenceTableGatherer>(new ConvergenceTableGatherer(inner->clone()));
}
