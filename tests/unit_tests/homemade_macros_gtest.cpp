/* GTest Macros */

#include <fstream>
#include <memory>
#include <cmath>

#include "homemade_macros_gtest.hpp"

using namespace std;

::testing::AssertionResult allVectorEntryAreEquallyNear(const std::vector <double> expected, const std::vector <double> actual, const double epsilon)
{
  bool success = true;
  std::string message;

  if(expected.size() != actual.size())
  {
    success = false;
    message = "Vectors don't have the same size";
  }
  else
  {
    std::vector<double>::const_iterator itExpected = expected.begin();
    for(std::vector<double>::const_iterator itActual = actual.begin(); itActual != actual.end(); ++itActual)
      //for(auto& itActual : actual)
    {
      if((std::abs(*itExpected - *itActual) > epsilon))
      {
        success = false;
        message = to_string(*itActual) + " is not equal to " + to_string(*itExpected) + " in the range of " + to_string(epsilon);
      }
      ++itExpected;
    }
  }

  ::testing::AssertionResult testedRes(success);
  testedRes << message;
  return testedRes;
}

::testing::AssertionResult bigIntMpzAreEqual(const BigIntMpz, const BigIntMpz)
{
  bool success = true;
  std::string message;

  ::testing::AssertionResult testedRes(success);
  testedRes << message;
  return testedRes;
}