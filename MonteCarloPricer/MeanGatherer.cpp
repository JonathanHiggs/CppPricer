#include "stdafx.h"
#include "MeanGatherer.h"



using namespace std;


// ## Mean Result ##
MeanResult::MeanResult(double mean)
	: mean(mean)
{}


void MeanResult::Serialize(ostream& os) const
{
	os << mean;
}


// ## Mean Gatherer ##
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


vector<StatisticResult*> MeanGatherer::GetResultsSoFar() const
{
	vector<StatisticResult*> results(1);

	results[0] = new MeanResult(runningSum / pathsDone);

	return results;
}


void MeanGatherer::Reset()
{
	runningSum = 0.0;
	pathsDone = 0UL;
}