// bigintmpz.h

#ifndef BIGINT_HPP
#define BIGINT_HPP

//#ifdef BIG_INT_SELECT_GMP
#include "bigIntMPZ.hpp"
typedef BigIntMpz BigInt;
/* #elif BIG_INT_SELECT_BOTAN
// #include <botan/....>
  typedef BigIntBotan BigInt;
#else
  #error "please define BIG_INT_SELECT_ to run..."
#endif */

#endif /* BIGINT_HPP */
