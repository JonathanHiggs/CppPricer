#pragma once


#include "StatisticsResult.h"
#include "ResultSet.h"
#include <memory>
#include <vector>


class StatisticsGatherer
{
public:
	StatisticsGatherer() {};
	virtual std::unique_ptr<StatisticsGatherer> clone() const = 0;
	virtual ~StatisticsGatherer() {};

	virtual void DumpOneResult(double result) = 0;
	virtual ResultSet GetResultsSoFar() const = 0;
	virtual void Reset() = 0;
};