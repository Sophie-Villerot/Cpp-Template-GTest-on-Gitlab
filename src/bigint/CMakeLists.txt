################################################
## SUB-LEVEL CMakeLists.txt for bigint folder ##
################################################

set(SRCS bigIntMPZ.cpp)

set(HEADERS bigInt.hpp
	    bigIntMPZ.hpp)

target_sources(${PROJECT_NAME}
               PRIVATE ${SRCS}
               PUBLIC  ${HEADERS})
