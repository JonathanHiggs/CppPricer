#pragma once


#include "PayOff.h"


class VanillaOption
{
public:
	VanillaOption(PayOff& payOff, double expiry);
	double GetExpiry() const;
	double OptionPayOff(double spot) const;

private:
	PayOff& payOff;
	double expiry;
};