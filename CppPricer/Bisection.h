#pragma once


namespace Pricer {
	namespace Solvers {

		template<class T>
		double Bisection(double target, double low, double high, double tolerance, T objectiveFunction)
		{
			double x = 0.5 * (low + high);
			double y = objectiveFunction(x);

			do
			{
				if (y < target)
					low = x;

				if (y > target)
					high = x;

				x = 0.5 * (low + high);
				y = objectiveFunction(x);
			} while (fabs(y - target) > tolerance);

			return x;
		}

	}
}