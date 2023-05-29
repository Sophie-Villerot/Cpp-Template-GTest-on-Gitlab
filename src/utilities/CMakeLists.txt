##################################################
## SUB-LEVEL CMakeLists.txt for verifier folder ##
##################################################

# set SRCS and HEADERS variable to .cpp/.hpp files
set(SRCS random.cpp
         evaluation.cpp)

set(HEADERS random.hpp
            evaluation.hpp)

target_sources(${PROJECT_NAME}
        PRIVATE ${SRCS}
        PUBLIC ${HEADERS})
