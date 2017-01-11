#include "stdafx.h"
#include "Parameter.h"


namespace Pricer {
	namespace Parameters {
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
	}
}