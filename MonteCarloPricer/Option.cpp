#include "stdafx.h"
#include "Option.h"


#if !defined(_MSC_VER)
using namespace std;
#endif


VanillaOption::VanillaOption(PayOff* payOff, double expiry)
	: expiry(expiry)
{
	this->payOff = std::unique_ptr<PayOff>(payOff);
}


double VanillaOption::GetExpiry() const
{
	return expiry;
}


double VanillaOption::OptionPayOff(double spot) const
{
	return (*payOff)(spot);
}