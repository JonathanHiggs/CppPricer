#pragma once


#include "StatisticsResult.h"


class MeanResult : public StatisticResult
{
public:
	MeanResult(double mean);

	virtual void Serialize(std::ostream& os) const;

private:
	double mean;
};