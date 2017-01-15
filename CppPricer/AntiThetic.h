#pragma once


#include "Random.h"


namespace Pricer {
	namespace Util {

		class AntiThetic : public RandomBase
		{
		public:
			AntiThetic(std::unique_ptr<RandomBase> innerGenerator);

			virtual std::unique_ptr<RandomBase> Clone() const;
			virtual void GetUniforms(std::vector<double>& variates);
			virtual void SetSeed(unsigned long seed);
			virtual void Skip(unsigned long numberOfPaths);
			virtual void ResetDimensionality(unsigned long newDimensionality);
			virtual void Reset();

		private:
			std::unique_ptr<RandomBase> innerGenerator;
			bool oddEven;
			std::vector<double> nextVariates;
		};

	}
}