#ifndef UTILITIES_RANDOM_HPP
#define UTILITIES_RANDOM_HPP

#include "bigint/bigInt.hpp"
#include <boost/random.hpp>

unsigned get_random_value(const unsigned low, const unsigned high);

namespace boost::random
{
  template<>
  class uniform_int_distribution<BigInt>
  {
  public:
    uniform_int_distribution(const BigInt& lowerLimit,
                             const BigInt& upperLimit)
    {
      assert(lowerLimit <= upperLimit);
      min = lowerLimit;
      max = upperLimit - lowerLimit;
    }

    //** Returns an integer uniformly distributed in the range [min, max]. *//
    template<class Engine>
    BigInt operator()(Engine& eng /*, unsigned seed_length=8 */) const
    {
      gmp_randclass randomState(gmp_randinit_default);
      /*
      unsigned seeds_needed = ceil(seed_length / sizeof(Engine::result_type)); // NEED correct function to get size
      // then: concatenate "seeds_needed" seeds after each other.
      //BigInt mySeed = 0;
      // for(unsigned i=0;i<seeds_needed;i++)
      //    mySeed = mySeed * (((BigInt)2) << (8*sizeof(Engine::result_type))) + ((BigInt) (eng()));
      //Engine::result_type engineSeed = eng();
       */
      unsigned long int engineSeed = eng();
      BigInt mySeed {(BigInt) engineSeed}; // Clean casting
      // seed() function accepts either mpz_class or unsigned long int
      randomState.seed(mySeed.getBigInt());

      // Random from mpz only draws between 0 and a given number
      // Hence drawing from [0, max-min)
      // Then adding back the min, to have a BigInt between [min, max)
      BigInt res = BigInt(randomState.get_z_range(max.getBigInt())) + min;

      return res;
    }

    BigInt operator()(BigInt &seedInput) const
    {
      gmp_randclass randomState(gmp_randinit_default);
      BigInt mySeed = seedInput;
      // seed() function accepts either mpz_class or unsigned long int
      randomState.seed(seedInput.getBigInt());

      // Random from mpz only draws between 0 and a given number
      // Hence drawing from [0, max-min)
      // Then adding back the min, to have a BigInt between [min, max)
      BigInt res = BigInt(randomState.get_z_range(max.getBigInt())) + min;

      return res;
    }

  private:
    BigInt min;
    BigInt max;
    BigInt mySeed;
  };
}

#endif // UTILITIES_RANDOM_HPP
