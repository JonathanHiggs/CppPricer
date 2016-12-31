#pragma once

#include "PayOff.h"


double SimpleMonteCarlo(
	const PayOff& payOff,
	double expiry,
	double spot,
	double vol,
	double discountRate,
	unsigned long numberOfPaths);