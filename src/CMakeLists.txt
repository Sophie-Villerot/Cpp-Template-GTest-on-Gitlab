####################################################
## src-LEVEL CMakeLists.txt to run the executable ##
####################################################

set(BINARY ${PROJECT_NAME})

# form the lib
add_library(${PROJECT_NAME} OBJECT ${SRCS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(${PROJECT_NAME}_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}>)
add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)


add_library(${PROJECT_NAME}_p2c STATIC)
set_property(TARGET ${PROJECT_NAME}_p2c PROPERTY POSITION_INDEPENDENT_CODE 1)

target_include_directories(${PROJECT_NAME}_p2c PUBLIC . ${Python_INCLUDE_DIRS} ${Python_NumPy_INCLUDE_DIRS} ${oatpp_INCLUDE_DIRS} ${oatpp-websocket_INCLUDE_DIRS})
#target_link_directories(${PROJECT_NAME}_p2c ${Python_LIBRARY_DIRS} ${Python_RUNTIME_LIBRARY_DIRS})
#target_link_libraries(${PROJECT_NAME}_p2c ${Python_LIBRARIES})

target_link_libraries(${PROJECT_NAME}_p2c ${Python_LIBRARIES} ${Python_SABI_LIBRARIES})
target_link_directories(${PROJECT_NAME}_p2c PRIVATE ${Python_LIBRARY_DIRS} ${Python_SABI_LIBRARY_DIRS})

# dependences declaration for GMP and Oatpp libs
target_link_libraries(${PROJECT_NAME} TAILED_DEP_LIBS)
target_include_directories(${PROJECT_NAME} PUBLIC ${oatpp_INCLUDE_DIRS} ${oatpp-websocket_INCLUDE_DIRS})

add_subdirectory(./bigint)
add_subdirectory(./utilities)

target_include_directories(${PROJECT_NAME} PUBLIC .)
