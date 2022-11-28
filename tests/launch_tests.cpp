#include "gtest/gtest.h"

using namespace std;
using namespace testing;

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv); // COMPULSORY
  return RUN_ALL_TESTS();
}

