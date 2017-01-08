#pragma once


#include "StatisticsGatherer.h"


class MeanResult : public StatisticResult
{
public:
	MeanResult(double mean);

	virtual void Serialize(std::ostream& os) const;

private:
	double mean;
};


class MeanGatherer : public StatisticsGatherer
{
public:
	MeanGatherer();
	virtual std::unique_ptr<StatisticsGatherer> clone() const;

	virtual void DumpOneResult(double result);
	virtual std::vector<StatisticResult*>GetResultsSoFar() const;
	virtual void Reset();

private:
	double runningSum;
	unsigned long pathsDone;
};