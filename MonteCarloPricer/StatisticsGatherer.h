#pragma once


#include <iostream>
#include <memory>
#include <vector>


class StatisticResult
{
public:
	StatisticResult() {};

	virtual void Serialize(std::ostream& os) const = 0;
};


std::ostream& operator << (std::ostream& os, const StatisticResult& result);
std::ostream& operator << (std::ostream& os, const StatisticResult* result);


class StatisticsGatherer
{
public:
	StatisticsGatherer() {};
	virtual std::unique_ptr<StatisticsGatherer> clone() const = 0;
	virtual ~StatisticsGatherer() {};

	virtual void DumpOneResult(double result) = 0;
	virtual std::vector<StatisticResult*> GetResultsSoFar() const = 0;
	virtual void Reset() = 0;
};