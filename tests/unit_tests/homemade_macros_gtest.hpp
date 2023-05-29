#ifndef HOME_MADE_MACROS_GTEST_HPP
#define HOME_MADE_MACROS_GTEST_HPP

#include "gtest/gtest.h"
#include "bigint/bigIntMPZ.hpp"
#include <vector>


::testing::AssertionResult allVectorEntryAreEquallyNear(const std::vector <double> expected, const std::vector
        <double> actual, const double epsilon);

::testing::AssertionResult bigIntMpzAreEqual(const BigIntMpz expectedBigIntMpz, const BigIntMpz actualBigIntMpz);

#endif //HOME_MADE_MACROS_GTEST_HPP

