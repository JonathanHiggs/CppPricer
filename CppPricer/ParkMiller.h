#pragma once


namespace Pricer {
	namespace Util {
		class ParkMiller
		{
		public:
			ParkMiller(long seed = 1);

			long GetOne();
			void SetSeed(long seed);

			static unsigned long Max();
			static unsigned long Min();

		private:
			long seed;
		};
	}
}