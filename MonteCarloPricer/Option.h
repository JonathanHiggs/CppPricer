#pragma once


#include "PayOffBridge.h"


class VanillaOption
{
public:
	VanillaOption(const PayOffBridge& payOff, double expiry);
	double GetExpiry() const;
	double OptionPayOff(double spot) const;

private:
	PayOffBridge payOff;
	double expiry;
};