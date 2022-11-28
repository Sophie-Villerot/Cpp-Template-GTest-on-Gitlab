####################################################
## src-LEVEL CMakeLists.txt to run the executable ##
####################################################

set(BINARY ${PROJECT_NAME})

# form the lib
add_library(${BINARY} ${SRCS})

add_subdirectory(./bigint)

target_include_directories(${PROJECT_NAME} PUBLIC .)
