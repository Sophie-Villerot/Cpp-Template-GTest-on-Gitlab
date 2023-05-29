#########################################################
## SUB-LEVEL CMakeLists.txt for utilities tests folder ##
#########################################################

set(SRCS utilitiesRandomUT.cpp
         utilitiesEvaluationUT.cpp)

target_sources(runUnitTests
               PRIVATE ${SRCS})
