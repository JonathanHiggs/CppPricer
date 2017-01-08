#include "stdafx.h"
#include "Parameter.h"


Parameter::Parameter(const ParameterInner& inner)
{
	innerParameter = inner.clone();
}


Parameter::Parameter(const Parameter& original)
{
	innerParameter = original.innerParameter->clone();
}


Parameter& Parameter::operator=(const Parameter& original)
{
	if (this != &original)
	{
		delete innerParameter;
		innerParameter = original.innerParameter->clone();
	}
	return *this;
}


Parameter::~Parameter()
{
	delete innerParameter;
}


double Parameter::Mean(double time1, double time2) const
{
	double total = Integral(time1, time2);
	return total / (time2 - time1);
}


double Parameter::RootMeanSquare(double time1, double time2) const
{
	double total = IntegralSquare(time1, time2);
	return total / (time2 - time1);
}


ParameterConstant::ParameterConstant(double constant)
	: constant(constant), constantSquare(constant * constant)
{ }


ParameterInner* ParameterConstant::clone() const
{
	return new ParameterConstant(*this);
}


double ParameterConstant::Integral(double time1, double time2) const
{
	return constant * (time2 - time1);
}


double ParameterConstant::IntegralSquare(double time1, double time2) const
{
	return constantSquare * (time2 - time1);
}




