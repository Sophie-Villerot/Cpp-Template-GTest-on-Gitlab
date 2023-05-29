#############################################################
## tests-LEVEL CMakeLists.txt to run the tests executables ##
#############################################################

add_subdirectory("${PROJECT_SOURCE_DIR}/include/googletest" "include/googletest")

# add the executable
# Edit to add more tests file *.cpp
add_executable(runUnitTests launch_tests.cpp)
add_subdirectory(unit_tests)
#add_executable(runFuncTests launch_tests.cpp)
#add_subdirectory(func_tests)


add_compile_definitions(BIG_INT_SELECT_GMP)

# Now simply link against gtest or gtest_main as needed
foreach(trgt runUnitTests) #runFuncTests)
  target_link_libraries(${trgt} PUBLIC ${CMAKE_PROJECT_NAME}_static ${CMAKE_PROJECT_NAME}_p2c gtest gtest_main ${TAILED_DEP_LIBS})
  #target_link_libraries(runFuncTests PUBLIC ${CMAKE_PROJECT_NAME}_static gtest gtest_main TAILED_DEP_LIBS)
  #target_link_libraries(runUnitTests gtest gtest_main pthread) #For multithreading
  target_include_directories(${trgt} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/googletest/googletest/include"
    "${PROJECT_SOURCE_DIR}/include/googletest/googlemock/include"
    ${TAILED_SRC_INCS}
    ${TAILED_DEP_INCS})
endforeach()

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME runUnitTests
         COMMAND runUnitTests)

#add_test(NAME runFuncTests
#         COMMAND runFuncTests)

#Run time max in seconds
set_tests_properties(runUnitTests PROPERTIES TIMEOUT 600)

#gtest_add_tests(TARGET runUnitTests
#                EXTRA_ARGS --gtest_output="xml:report.xml")
                #XML_OUTPUT_DIR  ../)
