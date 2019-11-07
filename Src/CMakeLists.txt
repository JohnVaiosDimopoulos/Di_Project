cmake_minimum_required(VERSION 3.15)
project(Sort_Join)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Tests)
add_executable(Sort_Join main.c Initializer/Relations_Initializer.c Initializer/Relations_Initializer.h Initializer/Argument_Manager.c Initializer/Argument_Manager.h Initializer/Arguments_Data.c Initializer/Relations_Initializer.h Util/Utilities.c Util/Utilities.h Initializer/Relation_Creator/Relation_Creator.c Initializer/Relation_Creator/Relation_Creator.h Basis_Structs/Tuple.h Histogram/Histogram.c Histogram/Histogram.h Prefix_sum/Prefix_Sum.c Prefix_sum/Prefix_Sum.h Basis_Structs/Relation.h Relation_Sorting/Relation_Sorting.c Relation_Sorting/Relation_Sorting.h Util/Quick_sort.c Util/Quick_sort.h Join/Join.c Join/Join.h)
