#pragma once


#include "PayOff.h"
#include <memory>


class VanillaOption
{
public:
	VanillaOption(PayOff* payOff, double expiry);
	double GetExpiry() const;
	double OptionPayOff(double spot) const;

private:
	std::unique_ptr<PayOff> payOff;
	double expiry;
};