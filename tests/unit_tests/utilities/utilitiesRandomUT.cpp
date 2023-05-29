#include "gtest/gtest.h"
#include "utilities/random.hpp"
#include <random>

using namespace std;
using namespace testing;

class ProbabilityDistributionParamTest : public ::testing::Test
{
protected:
  // Declare constructor
  ProbabilityDistributionParamTest() {}
  // Declare your variables
  // Assign values to your variables for the whole test set calling BigIntMpzTest
  virtual void SetUp() override
  {}
  // Free your variables if need be
  // virtual void TearDown() override {}
  ~ProbabilityDistributionParamTest() {}
};

// TEST_F = Test Fixture, which is allowed to used values in SetUp
TEST_F(ProbabilityDistributionParamTest, callToBigIntegerSpecialiazedRandomDistribFromZero)
{
  BigInt zero = BigInt::zero();
  BigInt hundred = BigInt("100");

  std::random_device rd;
  std::mt19937 gen(rd());
  boost::random::uniform_int_distribution<BigInt> dist(zero, hundred);

  for(int i=0; i< 100; i++)
  {
    BigInt randomBI = dist(gen);
    EXPECT_LT(randomBI, hundred) << "Boost template random distribution not working";
    EXPECT_GE(randomBI, zero) << "Boost template random distribution not working";
  }
}

TEST_F(ProbabilityDistributionParamTest, callToBigIntegerSpecialiazedRandomDistribFromTen)
{
  BigInt ten = BigInt("10");
  BigInt hundred = BigInt("100");

  std::random_device rd;
  std::mt19937 gen(rd());
  boost::random::uniform_int_distribution<BigInt> dist(ten, hundred);

  for(int i=0; i< 100; i++)
  {
    BigInt randomBI = dist(gen);
    EXPECT_LT(randomBI, hundred) << "Boost template random distribution not working";
    EXPECT_GE(randomBI, ten) << "Boost template random distribution not working";
  }
}

TEST_F(ProbabilityDistributionParamTest, callToBigIntegerSpecialiazedRandomDistribWithFixedSeed)
{
  BigInt ten = BigInt("10");
  BigInt hundred = BigInt("100");
  BigInt mySeed;
  int keyLength = 200;

  boost::random::uniform_int_distribution<BigInt> dist(ten, hundred);

  for(int i=0; i< 100; i++)
  {
    // Generate a new BigInt seed for each new step
    mySeed.randomUpToTwoPower(keyLength);

    BigInt randomBI = dist(mySeed);
    EXPECT_LT(randomBI, hundred) << "Boost template random distribution not working";
    EXPECT_GE(randomBI, ten) << "Boost template random distribution not working";
  }
}
