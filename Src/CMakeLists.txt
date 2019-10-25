cmake_minimum_required(VERSION 3.15)
project(Sort_Join)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Tests)
add_executable(Sort_Join main.c Initializer/Table_Initializer.c Initializer/Table_Initializer.h Initializer/Argument_Manager.c Initializer/Argument_Manager.h Initializer/Table_Files.c Initializer/Table_Initializer.h Util/Utilities.c Util/Utilities.h Initializer/Data_Table/Data_Table.c Initializer/Data_Table/Data_Table.h)
