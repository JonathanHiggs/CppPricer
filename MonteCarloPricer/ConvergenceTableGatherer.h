#pragma once

#include "stdafx.h"
#include "StatisticsGatherer.h"
#include "ResultTable.h"
#include <vector>


class ConvergenceTableGatherer : public StatisticsGatherer
{
public:
	ConvergenceTableGatherer(std::unique_ptr<StatisticsGatherer> inner);
	virtual std::unique_ptr<StatisticsGatherer> clone() const;

	virtual void DumpOneResult(double result);
	virtual ResultSet GetResultsSoFar() const;
	virtual void Reset();
	ResultTable GetResultTable() const;

private:
	std::unique_ptr<StatisticsGatherer> inner;
	ResultTable resultsSoFar;
	unsigned long stoppingPoint;
	unsigned long pathsDone;
};