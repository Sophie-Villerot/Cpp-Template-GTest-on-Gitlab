// random.cpp

#include <random> // from standard lib
#include "random.hpp"

unsigned get_random_value(const unsigned low, const unsigned high)
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high-1);
  return dist(gen);
}
