#pragma once

enum OptionType {
	call,
	put
};

class PayOff
{
public:
	PayOff(double strike_, OptionType optionType_);
	double operator()(double spot) const;

private:
	double Strike;
	OptionType Type;
};