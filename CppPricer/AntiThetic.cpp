#include "stdafx.h"
#include "AntiThetic.h"
#include <memory>


using namespace std;


namespace Pricer {
	namespace Util {

		AntiThetic::AntiThetic(unique_ptr<RandomBase> generator)
			: RandomBase(generator->GetDimensionality()), innerGenerator(move(generator)), oddEven(true)
		{
			innerGenerator->Reset();
			nextVariates.resize(GetDimensionality());
		}

		AntiThetic::AntiThetic(unique_ptr<RandomBase>& generator)
			: RandomBase(generator->GetDimensionality()), innerGenerator(move(generator)), oddEven(true)
		{
			innerGenerator->Reset();
			nextVariates.resize(GetDimensionality());
		}


		unique_ptr<RandomBase> AntiThetic::Clone() const
		{
			return unique_ptr<RandomBase>(new AntiThetic(innerGenerator->Clone()));
		}


		void AntiThetic::GetUniforms(vector<double>& variates)
		{
			if (oddEven)
			{
				innerGenerator->GetUniforms(variates);

				for (unsigned long i = 0; i < GetDimensionality(); i++)
					nextVariates[i] = 1.0 - variates[i];

				oddEven = false;
			}
			else
			{
				variates = nextVariates;
				oddEven = true;
			}
		}


		void AntiThetic::SetSeed(unsigned long seed)
		{
			innerGenerator->SetSeed(seed);
			oddEven = true;
		}


		void AntiThetic::Skip(unsigned long numberOfPaths)
		{
			if (numberOfPaths == 0)
				return;

			if (oddEven)
			{
				oddEven = false;
				numberOfPaths--;
			}

			innerGenerator->Skip(numberOfPaths / 2);

			if (numberOfPaths % 2)
			{
				vector<double> temp(GetDimensionality());
				GetUniforms(temp);
			}
		}


		void AntiThetic::ResetDimensionality(unsigned long newDimensionality)
		{
			RandomBase::ResetDimensionality(newDimensionality);
			nextVariates.resize(newDimensionality);
			innerGenerator->ResetDimensionality(newDimensionality);
		}


		void AntiThetic::Reset()
		{
			innerGenerator->Reset();
			oddEven = true;
		}
	}
}
