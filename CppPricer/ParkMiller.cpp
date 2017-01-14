#include "stdafx.h"
#include "ParkMiller.h"


namespace Pricer {
	namespace Util {

		const long a = 16807;
		const long m = 2147483647;
		const long q = 127773;
		const long r = 2836;


		ParkMiller::ParkMiller(long seed)
			: seed(seed)
		{}


		void ParkMiller::SetSeed(long newSeed)
		{
			seed = newSeed;
		}


		unsigned long ParkMiller::Max()
		{
			return m - 1;
		}


		unsigned long ParkMiller::Min()
		{
			return 1;
		}

		long ParkMiller::GetOne()
		{
			long k;

			k = seed / q;

			seed = a * (seed - k * q) - r * k;

			if (seed < 0)
				seed += m;

			return seed;
		}
	}
}