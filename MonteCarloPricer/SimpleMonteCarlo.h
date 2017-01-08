#pragma once

#include "Option.h"
#include "Parameter.h"
#include "StatisticsGatherer.h"


void SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	const Parameter& vol,
	const Parameter& discountRate,
	unsigned long numberOfPaths,
	StatisticsGatherer& gatherer
);