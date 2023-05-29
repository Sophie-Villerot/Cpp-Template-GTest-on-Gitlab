#include "gtest/gtest.h"
#include "utilities/evaluation.hpp"

using namespace std;
using namespace testing;

class EvaluationTest : public ::testing::Test
{
protected:
  // Declare constructor
  EvaluationTest() {}
  // Declare your variables
  // Assign values to your variables for the whole test set calling BigIntMpzTest
  virtual void SetUp() override
  {}
  // Free your variables if need be
  // virtual void TearDown() override {}
  ~EvaluationTest() {}
};

// TEST_F = Test Fixture, which is allowed to used values in SetUp
TEST_F(EvaluationTest, checkStringType)
{
  std::string myTest {"0"};
  // Note: std::String is an alias
  EXPECT_EQ(demangle(typeid(myTest).name()), "std::__cxx11::basic_string<char, "
                                                                        "std::char_traits<char>, "
                                                                        "std::allocator<char> >");
}

/*
TEST_F(EvaluationTest, checkStringVariableName)
{
  std::string myTest {"0"};
  std::string myVarName {"myTest"};
  EXPECT_EQ(NAMEOF(myTest), myVarName.c_str());
}
 */

