#include "stdafx.h"
#include "MeanGatherer.h"
#include "MeanResult.h"
#include <memory>


using namespace std;


MeanGatherer::MeanGatherer()
	: runningSum(0.0), pathsDone(0UL)
{}


unique_ptr<StatisticsGatherer> MeanGatherer::clone() const
{
	return unique_ptr<StatisticsGatherer>(new MeanGatherer(*this));
}


void MeanGatherer::DumpOneResult(double result)
{
	pathsDone++;
	runningSum += result;
}


ResultSet MeanGatherer::GetResultsSoFar() const
{
	ResultSet results;

	shared_ptr<StatisticResult> result{new MeanResult(runningSum / pathsDone)};

	results.Append(result);

	return results;
}


void MeanGatherer::Reset()
{
	runningSum = 0.0;
	pathsDone = 0UL;
}