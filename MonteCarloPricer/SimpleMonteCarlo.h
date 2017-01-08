#pragma once

#include "Option.h"
#include "Parameter.h"
#include "Statistics.h"


void SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	const Parameter& vol,
	const Parameter& discountRate,
	unsigned long numberOfPaths,
	Statistics& gatherer
);