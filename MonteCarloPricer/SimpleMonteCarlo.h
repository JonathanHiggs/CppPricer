#pragma once

#include "Option.h"
#include "Parameter.h"


double SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	const Parameter& vol,
	const Parameter& discountRate,
	unsigned long numberOfPaths);