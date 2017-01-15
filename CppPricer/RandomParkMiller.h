#pragma once


#include "Random.h"
#include "ParkMiller.h"


namespace Pricer {
	namespace Util {

		class RandomParkMiller : public RandomBase
		{
		public:
			RandomParkMiller(const unsigned long dimensionality, unsigned long seed = 1);

			virtual RandomParkMiller* Clone() const;
			virtual void GetUniforms(std::vector<double>& variates);
			virtual void Skip(unsigned long numberOfPaths);
			virtual void SetSeed(unsigned long seed);
			virtual void Reset();
			virtual void ResetDimensionality(unsigned long newDimensionality);

		private:
			ParkMiller innerGenerator;
			unsigned long initialSeed;
			double reciprocal;
		};

	}
}