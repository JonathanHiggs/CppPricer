#pragma once

#include "stdafx.h"
#include "Parameter.h"
#include <memory>


namespace Pricer {
	namespace Parameters {
		class ParameterConstant : public Parameter
		{
		public:
			ParameterConstant(double constant);

			virtual double Integral(double time1, double time2) const;
			virtual double IntegralSquare(double time1, double time2) const;

		private:
			double constant;
			double constantSquare;
		};
	}
}
