#ifndef SORT_JOIN_UTILITIES_H
#define SORT_JOIN_UTILITIES_H
#include <stdio.h>
#include <stdint.h>
#include "../Basis_Structs/Tuple.h"
char* Allocate_and_Copy_Str(const char*);
int Open_File_for_Read(FILE**,const char*);
Tuple_Ptr Allocate_Array(int Array_elements);
int Free_Array(Tuple_Ptr Array);
int generic_swap(void*,void*,int);
#endif //SORT_JOIN_UTILITIES_H
