#pragma once


#include <memory>
#include <vector>


namespace Pricer {
	namespace Util {

		class RandomBase
		{
		public:
			RandomBase(unsigned long dimensionality);

			inline unsigned long GetDimensionality() const { return dimensionality; };

			virtual std::unique_ptr<RandomBase> Clone() const = 0;
			virtual void GetUniforms(std::vector<double>& variates) = 0;
			virtual void Skip(unsigned long numberOfVariates) = 0;
			virtual void SetSeed(unsigned long seed) = 0;
			virtual void Reset() = 0;

			virtual void GetGaussians(std::vector<double>& variates);
			virtual void ResetDimensionality(unsigned long newDimensionality);

		private:
			unsigned long dimensionality;
		};
		

		double getOneGaussianBySimulation();
		double getOneGaussianByBoxMiller();
	}
}