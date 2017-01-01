#pragma once

#include "Option.h"


double SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	double vol,
	double discountRate,
	unsigned long numberOfPaths);