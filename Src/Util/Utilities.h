#ifndef SORT_JOIN_UTILITIES_H
#define SORT_JOIN_UTILITIES_H
#include <bits/types/FILE.h>
#include <stdint-gcc.h>
char* Allocate_and_Copy_Str(const char*);
int Open_File_for_Read(FILE**,const char*);
uint64_t ** Allocate_Array(int,int);
int Free_Array(uint64_t**,int);
#endif //SORT_JOIN_UTILITIES_H
