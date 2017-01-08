#include "stdafx.h"
#include "Statistics.h"
#include <vector>
#include <memory>


using namespace std;


StatisticsMean::StatisticsMean()
	: runningSum(0.0), pathsDone(0UL)
{}


void StatisticsMean::DumpOneResult(double result)
{
	pathsDone++;
	runningSum += result;
}


vector<vector<double>> StatisticsMean::GetResultsSoFar() const
{
	vector<vector<double>> results(1);

	results[0].resize(1);
	results[0][0] = runningSum / pathsDone;

	return results;
}


unique_ptr<Statistics> StatisticsMean::clone() const
{
	return unique_ptr<Statistics>(new StatisticsMean(*this));
}