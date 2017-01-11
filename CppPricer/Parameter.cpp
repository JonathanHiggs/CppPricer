#include "stdafx.h"
#include "Parameter.h"



namespace Pricer {
	namespace Parameters {
		// ## Parameter ##
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


		// ## ParameterConstant
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