#include "stdafx.h"
#include "ParameterConstant.h"


namespace Pricer {
	namespace Parameters {
		ParameterConstant::ParameterConstant(double constant)
			: constant(constant), constantSquare(constant * constant)
		{ }


		double ParameterConstant::Integral(double time1, double time2) const
		{
			return constant * (time2 - time1);
		}


		double ParameterConstant::IntegralSquare(double time1, double time2) const
		{
			return constantSquare * (time2 - time1);
		}
	}
}