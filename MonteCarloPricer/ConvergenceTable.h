#pragma once


#include "stdafx.h"
#include "Statistics.h"
#include <vector>


class ConvergenceTable : public Statistics
{
public:
	ConvergenceTable(Statistics& inner);
	ConvergenceTable(Statistics* inner);
	ConvergenceTable(std::unique_ptr<Statistics> inner);

	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;

	virtual std::unique_ptr<Statistics> clone() const;

private:
	std::unique_ptr<Statistics> inner;
	std::vector<std::vector<double>> resultsSoFar;
	unsigned long stoppingPoint;
	unsigned long pathsDone;
};