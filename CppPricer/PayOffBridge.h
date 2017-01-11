#pragma once

#include "PayOff.h"

class PayOffBridge
{
public:
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge(const PayOff& innerPayOff);

	inline double operator()(double spot) const;
	~PayOffBridge();
	PayOffBridge& operator= (const PayOffBridge& original);

private:
	PayOff* payOff;
};


inline double PayOffBridge::operator()(double spot) const
{
	return (*payOff)(spot);
}