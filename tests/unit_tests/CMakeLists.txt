###########################################################
## unit-tests-LEVEL CMakeLists.txt to run the executable ##
###########################################################


add_subdirectory(./bigint)
add_subdirectory(./utilities)

target_include_directories(runUnitTests PUBLIC .)
