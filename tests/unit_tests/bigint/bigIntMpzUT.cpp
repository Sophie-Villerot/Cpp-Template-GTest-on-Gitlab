#include "gtest/gtest.h"
#include "bigint/bigIntMPZ.hpp"

using namespace std;
using namespace testing;


static const string fbiStr = "1200075084";
static const string sbiStr = "837928734762534763";


class BigIntMpzTest : public ::testing::Test
{
protected:
  // Declare constructor
  BigIntMpzTest() {}
  // Declare your variables
  BigIntMpz m_firstBIM;
  BigIntMpz m_secBIM;
  // Assign values to your variables for the whole test set calling BigIntMpzTest
  virtual void SetUp() override
  {
    m_firstBIM = BigIntMpz(fbiStr);
    m_secBIM = BigIntMpz(sbiStr);
  }
  // Free your variables if need be
  // virtual void TearDown() override {}
  ~BigIntMpzTest() {}
};


// TEST_F = Test Fixture, which is allowed to used values in SetUp
TEST_F(BigIntMpzTest, worksWithOstream)
{
  std::ostringstream oss;
  oss << m_firstBIM ;
  EXPECT_EQ(oss.str(), "1200075084") << "Writing BigIntMpz in stream not working";
}

TEST_F(BigIntMpzTest, worksWithComparisonOp)
{
  EXPECT_TRUE(m_firstBIM != m_secBIM) << "Overloaded != op. for BigIntMpz not working";

  EXPECT_TRUE(m_firstBIM < m_secBIM) << "Overloaded < op. for BigIntMpz not working";
  EXPECT_FALSE(m_secBIM < m_firstBIM) << "Overloaded < op. for BigIntMpz not working";

  EXPECT_TRUE(m_firstBIM <= m_secBIM) << "Overloaded <= op. for BigIntMpz not working";
  EXPECT_FALSE(m_secBIM <= m_firstBIM) << "Overloaded <= op. for BigIntMpz not working";

  EXPECT_TRUE(m_secBIM > m_firstBIM) << "Overloaded > op. for BigIntMpz not working";
  EXPECT_FALSE(m_firstBIM > m_secBIM) << "Overloaded > op. for BigIntMpz not working";

  EXPECT_TRUE(m_secBIM >= m_firstBIM) << "Overloaded >= op. for BigIntMpz not working";
  EXPECT_FALSE(m_firstBIM >= m_secBIM) << "Overloaded >= op. for BigIntMpz not working";

  BigIntMpz m_firstBIMcc(m_firstBIM);
  EXPECT_TRUE(m_firstBIM == m_firstBIMcc) << "Overloaded == op. for BigIntMpz not working";
  EXPECT_TRUE(m_firstBIM <= m_firstBIMcc) << "Overloaded =< op. for BigIntMpz not working";
  EXPECT_TRUE(m_firstBIM >= m_firstBIMcc) << "Overloaded >= op. for BigIntMpz not working";
}

// Note: = sign is correctly overloaded by ASSER_EQ func.
TEST_F(BigIntMpzTest, worksWithAddition)
{
  BigIntMpz res = m_firstBIM + m_secBIM;
  BigIntMpz expectedRes = BigIntMpz("837928735962609847");
  EXPECT_EQ(res, expectedRes) << "Overloaded addition not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithSubstraction)
{
  BigIntMpz res = m_secBIM - m_firstBIM;
  BigIntMpz expectedRes = BigIntMpz("837928733562459679");
  EXPECT_EQ(res, expectedRes) << "Overloaded subtraction not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithMultiplication)
{
  BigIntMpz res = m_firstBIM * m_secBIM;
  BigIntMpz expectedRes = BigIntMpz("1005577396756162625760145092");
  EXPECT_EQ(res, expectedRes) << "Overloaded multiplication not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithDivision)
{
  BigIntMpz res = m_secBIM / m_firstBIM;
  BigIntMpz expectedRes = BigIntMpz("698230257");
  EXPECT_EQ(res, expectedRes) << "Overloaded division not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithModulo)
{
  BigIntMpz res = m_secBIM % m_firstBIM;
  BigIntMpz expectedRes = BigIntMpz("441918175");
  EXPECT_EQ(res, expectedRes) << "Overloaded modulo operator not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithAdditionMultiplication)
{
  BigIntMpz res = BigIntMpz(2);
  addmul(res, m_secBIM, m_firstBIM);
  BigIntMpz expectedRes = BigIntMpz("1005577396756162625760145094");
  EXPECT_EQ(res, expectedRes) << "Addmul function not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithPowerAndModulo)
{
  BigIntMpz base = BigIntMpz(2);
  BigIntMpz res;
  powm_sec(res, base, m_firstBIM, m_secBIM);
  BigIntMpz expectedRes = BigIntMpz("453288367041325003");
  EXPECT_EQ(res, expectedRes) << "powm_sec function not working for BigIntMpz class derived from GMP C++ interface";
}

TEST_F(BigIntMpzTest, worksWithPrimeTest)
{
  int reps = 50;
  BigIntMpz prime = BigIntMpz("13");
  BigIntMpz secPrime = BigIntMpz("1000000009991");
  BigIntMpz firstPrime = BigIntMpz("987098385947");
  BigIntMpz fourthPrime = BigIntMpz("31699");
  BigIntMpz fifthPrime = BigIntMpz("109199");
  BigIntMpz sixthPrime = BigIntMpz("1022071");
  BigIntMpz seventhPrime = BigIntMpz("10067221");
  BigIntMpz eighthPrime = BigIntMpz("1006726073");

  EXPECT_TRUE(testIfPrime(prime, reps)) << "13 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(fourthPrime, reps)) << "31699 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(fifthPrime, reps)) << "109199 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(sixthPrime, reps)) << "1022071 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(seventhPrime, reps)) << "10067221 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(eighthPrime, reps)) << "1006726073 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(secPrime, reps)) << "1000000009991 is NOT a prime number";
  EXPECT_TRUE(testIfPrime(firstPrime, reps)) << "987098385947 is NOT a prime number";
}

TEST_F(BigIntMpzTest, worksWithConstants)
{
  std::ostringstream oss;
  oss << BigIntMpz::zero() ;
  EXPECT_EQ(oss.str(), "0") << "Constant func creation for BigIntMpz::zero() not working";

  oss.str("");
  oss.clear();
  oss << BigIntMpz::one();
  EXPECT_EQ(oss.str(), "1") << "Constant func creation for BigIntMpz::one() not working";
}

TEST_F(BigIntMpzTest, checkCreationsFromDoubles)
{
  BigIntMpz roundedTowardZero = BigIntMpz(13.1234);
  BigIntMpz roundedTowardCeil = BigIntMpz(13.5);

  EXPECT_EQ(roundedTowardZero.toString(), "13");
  EXPECT_EQ(roundedTowardCeil.toString(), "14");

  BigIntMpz roundedTowardZeroNeg = BigIntMpz(-13.1234);
  BigIntMpz roundedTowardCeilNeg = BigIntMpz(-13.5);

  EXPECT_EQ(roundedTowardZeroNeg.toString(), "-13");
  EXPECT_EQ(roundedTowardCeilNeg.toString(), "-14");
}

TEST_F(BigIntMpzTest, worksWithIntegerLog)
{
  BigIntMpz prime = BigIntMpz("13");
  BigIntMpz secPrime = BigIntMpz("1000000009991");
  BigIntMpz firstPrime = BigIntMpz("987098385947");
  BigIntMpz fourthPrime = BigIntMpz("31699");
  BigIntMpz fifthPrime = BigIntMpz("109199");
  BigIntMpz sixthPrime = BigIntMpz("1022071");
  BigIntMpz seventhPrime = BigIntMpz("10067221");
  BigIntMpz eighthPrime = BigIntMpz("1006726073");

  EXPECT_EQ(log_in_base(prime, 2), 4) << "Log(13) in 2-base not working";
  EXPECT_EQ(log_in_base(secPrime, 2), 40) << "Log(1000000009991) in 2-base not working";
  EXPECT_EQ(log_in_base(firstPrime, 15), 11) << "Log(987098385947) in 15-base not working";
  EXPECT_EQ(log_in_base(fourthPrime, 15), 4) << "Log(31699) in 15-base not working";
  EXPECT_EQ(log_in_base(fifthPrime, 32), 4) << "Log(109199) in 32-base not working";
  EXPECT_EQ(log_in_base(sixthPrime, 32), 4) << "Log(1022071) in 32-base not working";
  EXPECT_EQ(log_in_base(seventhPrime, 56), 5) << "Log(10067221) in 56-base not working";
  EXPECT_EQ(log_in_base(eighthPrime, 57), 6) << "Log(1006726073) in 57-base not working";
}

TEST_F(BigIntMpzTest, worksWithIntegerLog_2)
{
  BigIntMpz prime = BigIntMpz("13");
  BigIntMpz secPrime = BigIntMpz("1000000009991");
  BigIntMpz firstPrime = BigIntMpz("987098385947");
  BigIntMpz fourthPrime = BigIntMpz("31699");
  BigIntMpz fifthPrime = BigIntMpz("109199");
  BigIntMpz sixthPrime = BigIntMpz("1022071");
  BigIntMpz seventhPrime = BigIntMpz("10067221");
  BigIntMpz eighthPrime = BigIntMpz("1006726073");

  EXPECT_EQ(log_in_2base(prime), 4) << "Log(13) in 2-base not working";
  EXPECT_EQ(log_in_2base(secPrime), 40) << "Log(1000000009991) in 2-base not working";
  EXPECT_EQ(log_in_2base(firstPrime), 40) << "Log(987098385947) in 2-base not working";
  EXPECT_EQ(log_in_2base(fourthPrime), 15) << "Log(31699) in 2-base not working";
  EXPECT_EQ(log_in_2base(fifthPrime), 17) << "Log(109199) in 2-base not working";
  EXPECT_EQ(log_in_2base(sixthPrime), 20) << "Log(1022071) in 2-base not working";
  EXPECT_EQ(log_in_2base(seventhPrime), 24) << "Log(10067221) in 2-base not working";
  EXPECT_EQ(log_in_2base(eighthPrime), 30) << "Log(1006726073) in 2-base not working";
}

TEST_F(BigIntMpzTest, worksWithIntegerDecompositionIntoBits)
{
  // Checks made using: https://www.rapidtables.com/convert/number/decimal-to-binary.html
  BigIntMpz prime = BigIntMpz("13");
  std::vector<bool> primeIntoBits{1,0,1,1};
  EXPECT_EQ(decomposeIntoBits(prime), primeIntoBits) << "Conversion of 13 into binary not working";

  BigIntMpz secPrime = BigIntMpz("1000000009991");
  std::vector<bool> secPrimeIntoBits{1,1,1,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,1,1,1};
  EXPECT_EQ(decomposeIntoBits(secPrime), secPrimeIntoBits) << "Conversion of 1000000009991 into binary not working";

  BigIntMpz firstPrime = BigIntMpz("987098385947");
  std::vector<bool> firstPrimeIntoBits{1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1};
  EXPECT_EQ(decomposeIntoBits(firstPrime), firstPrimeIntoBits) << "Conversion of 987098385947 into binary not working";

  BigIntMpz fourthPrime = BigIntMpz("31699");
  std::vector<bool> fourthPrimeIntoBits{1,1,0,0,1,0,1,1,1,1,0,1,1,1,1};
  EXPECT_EQ(decomposeIntoBits(fourthPrime), fourthPrimeIntoBits) << "Conversion of 31699 into binary not working";

  BigIntMpz fifthPrime = BigIntMpz("109199");
  std::vector<bool> fifthPrimeIntoBits{1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1};
  EXPECT_EQ(decomposeIntoBits(fifthPrime), fifthPrimeIntoBits) << "Conversion of 109199 into binary not working";

  BigIntMpz sixthPrime = BigIntMpz("1022071");
  std::vector<bool> sixthPrimeIntoBits{1,1,1,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1};
  EXPECT_EQ(decomposeIntoBits(sixthPrime), sixthPrimeIntoBits) << "Conversion of 1022071 into binary not working";

  BigIntMpz seventhPrime = BigIntMpz("10067221");
  std::vector<bool> seventhPrimeIntoBits{1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1};
  EXPECT_EQ(decomposeIntoBits(seventhPrime), seventhPrimeIntoBits) << "Conversion of 10067221 into binary not working";

  BigIntMpz eighthPrime = BigIntMpz("1006726073");
  std::vector<bool> eighthPrimeIntoBits{1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1};
  EXPECT_EQ(decomposeIntoBits(eighthPrime), eighthPrimeIntoBits) << "Conversion of 1006726073 into binary not working";
}