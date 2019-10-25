cmake_minimum_required(VERSION 3.15)
project(Sort_Join)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Tests)
add_executable(Sort_Join main.c Initializer/Initializer.c Initializer/Initializer.h Initializer/Argument_Manager.c Initializer/Argument_Manager.h Initializer/Table_Files.c Initializer/Initializer.h Util/String_Managing.c Util/String_Managing.h )
add_executable(Initializer/main.c)