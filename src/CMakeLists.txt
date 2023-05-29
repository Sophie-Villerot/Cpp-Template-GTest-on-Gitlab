####################################################
## src-LEVEL CMakeLists.txt to run the executable ##
####################################################

set(BINARY ${PROJECT_NAME})

# form the lib
add_library(${PROJECT_NAME} OBJECT ${SRCS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(${PROJECT_NAME}_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}>)
add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)


add_subdirectory(./bigint)
add_subdirectory(./utilities)

target_link_libraries(${PROJECT_NAME} CPPTEMPLATE_DEP_LIBS)
target_include_directories(${PROJECT_NAME} PUBLIC .)
