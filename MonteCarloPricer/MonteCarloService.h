#pragma once


#include "Option.h"
#include "Parameter.h"
#include "StatisticsGatherer.h"


class MonteCarloService
{
public:
	MonteCarloService();

	void Run(
		const VanillaOption& option,
		double spot,
		const Parameter& volatility,
		const Parameter& discountRate,
		unsigned long numberOfPaths,
		StatisticsGatherer& statisticsGatherer
	) const;
};