#pragma once


#include <vector>
#include <memory>


class Statistics
{
public:
	Statistics() {};

	virtual void DumpOneResult(double result) = 0;
	virtual std::vector<std::vector<double>> GetResultsSoFar() const = 0;

	virtual std::unique_ptr<Statistics> clone() const = 0;
	virtual ~Statistics() {};
};


class StatisticsMean : public Statistics
{
public:
	StatisticsMean();
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>>GetResultsSoFar() const;

	virtual std::unique_ptr<Statistics> clone() const;


private:
	double runningSum;
	unsigned long pathsDone;
};