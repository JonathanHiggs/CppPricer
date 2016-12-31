#pragma once


class PayOff
{
public:
	PayOff() {};
	virtual double operator()(double spot) const = 0;
	virtual ~PayOff() {};
};


class PayOffCall : public PayOff
{
public:
	PayOffCall(double strike);
	virtual double operator() (double spot) const;
	virtual ~PayOffCall() {};

private:
	double Strike;
};


class PayOffPut : public PayOff
{
public:
	PayOffPut(double strike);
	virtual double operator() (double spot) const;
	virtual ~PayOffPut() {};

private:
	double Strike;
};


class PayOffDigitalCall : public PayOff
{
public:
	PayOffDigitalCall(double strike);
	virtual double operator() (double spot) const;
	virtual ~PayOffDigitalCall() {};

private:
	double Strike;
};


class PayOffDigitalPut : public PayOff
{
public:
	PayOffDigitalPut(double strike);
	virtual double operator() (double spot) const;
	virtual ~PayOffDigitalPut() {};

private:
	double Strike;
};


class PayOffDoubleDigital : public PayOff
{
public:
	PayOffDoubleDigital(double lowerLevel, double upperLevel);
	virtual double operator() (double spot) const;
	virtual ~PayOffDoubleDigital() {};

private:
	double LowerLevel;
	double UpperLevel;
};