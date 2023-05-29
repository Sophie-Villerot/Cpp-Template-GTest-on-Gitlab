#ifndef UTILITIES_LAZYEVAL_HPP
#define UTILITIES_LAZYEVAL_HPP

// See: https://stackoverflow.com/questions/38696440/a-standard-way-for-getting-variable-name-at-compile-time
#define NAMEOF(variable) ((decltype(&variable))nullptr)

#include <cxxabi.h>
#include <cstdlib>
#include <memory>
#include <string>


std::string demangle(char const* mangled);



#endif // UTILITIES_LAZYEVAL_HPP