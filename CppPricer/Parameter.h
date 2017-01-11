#pragma once

#include "stdafx.h"
#include <memory>


namespace Pricer {
	namespace Parameters {
		class Parameter
		{
		public:
			virtual double Integral(double time1, double time2) const = 0;
			virtual double IntegralSquare(double time1, double time2) const = 0;
			virtual double Mean(double time1, double time2) const;
			virtual double RootMeanSquare(double time1, double time2) const;
		};
	}
}
