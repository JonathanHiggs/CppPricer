#include "stdafx.h"
#include "Random.h"
#include "StandardNormalDistribution.h"
#include <random>
#include <cstdlib>
#include <cmath>


using namespace std;


namespace Pricer {
	namespace Util {

		RandomBase::RandomBase(unsigned long dimensionality)
			: dimensionality(dimensionality)
		{}


		void RandomBase::GetGaussians(vector<double>& variates)
		{
			GetUniforms(variates);

			for (unsigned long i = 0; i < dimensionality; i++)
			{
				double x = variates[i];
				variates[i] = StandardNormalDistribution::InverseCumulativeDensity(x);
			}
		}


		void RandomBase::ResetDimensionality(unsigned long newDimensionality)
		{
			dimensionality = newDimensionality;
		}


		double getOneGaussianBySimulation() {
			double result = 0;

			for (unsigned long j = 0; j < 12; j++)
				result += rand() / static_cast<double>(RAND_MAX);

			result -= 6.0;

			return result;
		}


		double getOneGaussianByBoxMiller() {
			double result;

			double x, y;
			double sizeSquared;

			do {
				x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
				y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
				sizeSquared = x * x + y * y;
			} while (sizeSquared >= 1.0);

			result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

			return result;
		}
	}
}