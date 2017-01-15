#include "stdafx.h"
#include "RandomParkMiller.h"


using namespace std;


namespace Pricer {
	namespace Util {

		RandomParkMiller::RandomParkMiller(const unsigned long dimensionality, unsigned long seed)
			: RandomBase(dimensionality), innerGenerator(seed), initialSeed(seed)
		{
			reciprocal = 1.0 / (1.0 + innerGenerator.Max());
		}


		RandomParkMiller* RandomParkMiller::Clone() const
		{
			return new RandomParkMiller(GetDimensionality(), initialSeed);
		}


		void RandomParkMiller::GetUniforms(vector<double>& variates)
		{
			for (unsigned long j = 0; j < GetDimensionality(); j++)
				variates[j] = innerGenerator.GetOne() * reciprocal;
		}


		void RandomParkMiller::Skip(unsigned long numberOfPaths)
		{
			vector<double> temp(GetDimensionality());
			for (unsigned long j = 0; j < numberOfPaths; j++)
				GetUniforms(temp);
		}


		void RandomParkMiller::SetSeed(unsigned long seed)
		{
			initialSeed = seed;
			innerGenerator.SetSeed(seed);
		}


		void RandomParkMiller::Reset()
		{
			innerGenerator.SetSeed(initialSeed);
		}


		void RandomParkMiller::ResetDimensionality(unsigned long newDimensionality)
		{
			RandomBase::ResetDimensionality(newDimensionality);
			innerGenerator.SetSeed(initialSeed);
		}
	}
}