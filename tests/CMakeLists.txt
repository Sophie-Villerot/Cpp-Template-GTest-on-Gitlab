######################################################
## tests-LEVEL CMakeLists.txt to run the executable ##
######################################################

add_subdirectory("${PROJECT_SOURCE_DIR}/include/googletest" "include/googletest")

# add the executable
# Edit to add more tests file *.cpp
add_executable(runUnitTests launch_tests.cpp unit_tests/BigIntMpz_UT.cpp)

# dependences declaration for GMP
target_link_libraries(${PROJECT_NAME})

# Now simply link against gtest or gtest_main as needed
target_link_libraries(runUnitTests PUBLIC ${CMAKE_PROJECT_NAME} gtest gtest_main)
#target_link_libraries(runUnitTests gtest gtest_main pthread) #For multithreading

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include/googletest/googletest/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include/googletest/googlemock/include")

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME runUnitTests
         COMMAND runUnitTests)

set_tests_properties(runUnitTests PROPERTIES TIMEOUT 10)
