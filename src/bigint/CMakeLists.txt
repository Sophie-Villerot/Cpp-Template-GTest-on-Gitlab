################################################
## SUB-LEVEL CMakeLists.txt for bigint folder ##
################################################

set(SRCS bigintmpz.cpp)

set(HEADERS bigint.hpp
            bigintmpz.hpp)

target_sources(${PROJECT_NAME}
  PRIVATE ${SRCS}
  PUBLIC  ${HEADERS}
  )
