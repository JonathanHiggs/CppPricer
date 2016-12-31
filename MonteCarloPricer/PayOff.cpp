#include "stdafx.h"
#include "PayOff.h"
#include <minmax.h>


// Call
PayOffCall::PayOffCall(double strike)
	: Strike(strike)
{}


double PayOffCall::operator()(double spot) const
{
	return max(spot - Strike, 0.0);
}


// Put
PayOffPut::PayOffPut(double strike)
	: Strike(strike)
{}


double PayOffPut::operator()(double spot) const
{
	return max(Strike - spot, 0.0);
}


// Digital Call
PayOffDigitalCall::PayOffDigitalCall(double strike)
	: Strike(strike)
{}


double PayOffDigitalCall::operator()(double spot) const
{
	return spot > Strike ? 1.0 : 0.0;
}


// Digital Put
PayOffDigitalPut::PayOffDigitalPut(double strike)
	: Strike(strike)
{}


double PayOffDigitalPut::operator()(double spot) const
{
	return Strike > spot ? 1.0 : 0.0;
}


// Double Digital
PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel, double upperLevel)
	: LowerLevel(lowerLevel), UpperLevel(upperLevel)
{}


double PayOffDoubleDigital::operator()(double spot) const
{
	return LowerLevel < spot && spot < UpperLevel ? 1.0 : 0.0;
}