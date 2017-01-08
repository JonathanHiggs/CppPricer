#pragma once


#include "StatisticsResult.h"


class NumberOfPathsResult : public StatisticResult
{
public:
	NumberOfPathsResult(int numberOfPaths);

	virtual void Serialize(std::ostream& os) const { os << numberOfPaths; };

private:
	int numberOfPaths;
};