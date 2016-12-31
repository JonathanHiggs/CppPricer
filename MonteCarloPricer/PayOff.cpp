#include "stdafx.h"
#include "PayOff.h"
#include <minmax.h>

PayOff::PayOff(double strike_, OptionType optionType_)
	: Strike(strike_), Type(optionType_)
{}


double PayOff::operator()(double spot) const
{
	switch (Type)
	{
	case call:
		return max(spot - Strike, 0.0);

	case put:
		return max(Strike - spot, 0.0);

	default:
		throw("Unknown option type found");
	}
}