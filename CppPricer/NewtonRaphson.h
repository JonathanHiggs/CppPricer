#pragma once


namespace Pricer {
	namespace Solvers {

		template<class T, double (T::*value)(double) const, double (T::*derivative)(double) const>
		double NewtonRaphson(double target, double start, double tolerance, const T& obj)
		{
			double y = (obj.*value)(start);
			double x = start;

			while (abs(y - target) > tolerance)
			{
				double d = (obj.*derivative)(x);
				x += (target - y) / d;
				y = (obj.*value)(x);
			}

			return x;
		}

	}
}
