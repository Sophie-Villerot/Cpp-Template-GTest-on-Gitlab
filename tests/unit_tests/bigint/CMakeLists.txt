######################################################
## SUB-LEVEL CMakeLists.txt for bigint tests folder ##
######################################################

set(SRCS bigIntMpzUT.cpp)

target_sources(runUnitTests
               PRIVATE ${SRCS})
