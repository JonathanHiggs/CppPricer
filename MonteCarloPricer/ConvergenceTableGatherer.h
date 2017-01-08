#pragma once


#include "stdafx.h"
#include "StatisticsGatherer.h"
#include <vector>


class ConvergenceTableGatherer
{
public:
	ConvergenceTableGatherer(StatisticsGatherer& inner);
	ConvergenceTableGatherer(StatisticsGatherer* inner);
	ConvergenceTableGatherer(std::unique_ptr<StatisticsGatherer> inner);

	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<StatisticResult*>> GetResultsSoFar() const;

	virtual std::unique_ptr<ConvergenceTableGatherer> clone() const;

private:
	std::unique_ptr<StatisticsGatherer> inner;
	std::vector<std::vector<StatisticResult*>> resultsSoFar;
	unsigned long stoppingPoint;
	unsigned long pathsDone;
};