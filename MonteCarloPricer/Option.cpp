#include "stdafx.h"
#include "Option.h"
#include "PayOff.h"

#if !defined(_MSC_VER)
using namespace std;
#endif


VanillaOption::VanillaOption(PayOff& payOff, double expiry)
	: payOff(payOff), expiry(expiry)
{}


double VanillaOption::GetExpiry() const
{
	return expiry;
}


double VanillaOption::OptionPayOff(double spot) const
{
	return payOff(spot);
}