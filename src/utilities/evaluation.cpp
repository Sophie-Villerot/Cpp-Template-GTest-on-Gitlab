#include "evaluation.hpp"


// Taken from: https://stackoverflow.com/questions/1024648/retrieving-a-c-class-name-programmatically
std::string demangle(char const* mangled)
{
auto ptr = std::unique_ptr<char, decltype(& std::free)>{abi::__cxa_demangle(mangled,
                                                                            nullptr,
                                                                            nullptr,
                                                                            nullptr),
                                                        std::free};
return {ptr.get()};
}