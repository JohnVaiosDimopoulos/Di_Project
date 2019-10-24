cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Test Initializer/Argument_Manager_Tests.cpp Test_main.cpp Initializer/Table_Files_Test.cpp Util/String_Managing_Tests.cpp Initializer/Initializer_Tests.cpp)

target_link_libraries(Test gtest gtest_main)