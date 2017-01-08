#pragma once

#include "stdafx.h"


class ParameterInner
{
public:
	ParameterInner() {};

	virtual ParameterInner* clone() const = 0;
	virtual double Integral(double time1, double time2) const = 0;
	virtual double IntegralSquare(double time1, double time2) const = 0;
	virtual ~ParameterInner() {};
};


class Parameter
{
public:
	Parameter(const ParameterInner& innerParameter);
	Parameter(const Parameter& original);
	Parameter& operator=(const Parameter& original);

	virtual ~Parameter();

	inline double Integral(double time1, double time2) const;
	inline double IntegralSquare(double time1, double time2) const;
	
	double Mean(double time1, double time2) const;
	double RootMeanSquare(double time1, double time2) const;

private:
	ParameterInner* innerParameter;
};


inline double Parameter::Integral(double time1, double time2) const
{
	return innerParameter->Integral(time1, time2);
}


inline double Parameter::IntegralSquare(double time1, double time2) const
{
	return innerParameter->IntegralSquare(time1, time2);
}


class ParameterConstant : public ParameterInner
{
public:
	ParameterConstant(double constant);

	virtual ParameterInner* clone() const;
	virtual double Integral(double time1, double time2) const;
	virtual double IntegralSquare(double time1, double time2) const;

private:
	double constant;
	double constantSquare;
};