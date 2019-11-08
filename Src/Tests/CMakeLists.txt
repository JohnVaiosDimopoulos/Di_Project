cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Test Initializer/Argument_Manager_Tests.cpp Test_main.cpp Initializer/Argument_Data_Test.cpp Util/Utilities_Tests.cpp Initializer/Relation_Creator/Relation_Creatior_Tests.cpp Prefix_Sum/Prefix_Sum_Tests.cpp Initializer/Relation_Initializer_Test.cpp Histogram/Histogram_Tests.cpp Relation_Sorting/Relation_Sorting_Test.cpp Result_List/Result_List_Tests.cpp Join/Join_Tests.cpp)

target_link_libraries(Test gtest gtest_main)