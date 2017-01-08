#include "stdafx.h"
#include "PayOff.h"
#include <minmax.h>


// Call
PayOffCall::PayOffCall(double strike)
	: strike(strike)
{}


double PayOffCall::operator()(double spot) const
{
	return max(spot - strike, 0.0);
}


PayOffCall* PayOffCall::clone() const
{
	return new PayOffCall(strike);
}


// Put
PayOffPut::PayOffPut(double strike)
	: Strike(strike)
{}


double PayOffPut::operator()(double spot) const
{
	return max(Strike - spot, 0.0);
}


PayOffPut* PayOffPut::clone() const
{
	return new PayOffPut(Strike);
}


// Digital Call
PayOffDigitalCall::PayOffDigitalCall(double strike)
	: Strike(strike)
{}


double PayOffDigitalCall::operator()(double spot) const
{
	return spot > Strike ? 1.0 : 0.0;
}


PayOffDigitalCall* PayOffDigitalCall::clone() const
{
	return new PayOffDigitalCall(Strike);
}


// Digital Put
PayOffDigitalPut::PayOffDigitalPut(double strike)
	: Strike(strike)
{}


double PayOffDigitalPut::operator()(double spot) const
{
	return Strike > spot ? 1.0 : 0.0;
}


PayOffDigitalPut* PayOffDigitalPut::clone() const
{
	return new PayOffDigitalPut(Strike);
}


// Double Digital
PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel, double upperLevel)
	: LowerLevel(lowerLevel), UpperLevel(upperLevel)
{}


double PayOffDoubleDigital::operator()(double spot) const
{
	return LowerLevel < spot && spot < UpperLevel ? 1.0 : 0.0;
}


PayOffDoubleDigital* PayOffDoubleDigital::clone() const
{
	return new PayOffDoubleDigital(LowerLevel, UpperLevel);
}