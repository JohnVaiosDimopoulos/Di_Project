#ifndef SORT_JOIN_DATA_PREFIX_SUM_H
#define SORT_JOIN_DATA_PREFIX_SUM_H

#include <stdio.h>
#include <stdint.h>
#include "../Basis_Structs/Psum_Tuple.h"

typedef struct Psum* Psum_Ptr;

Psum_Ptr Get_Psum(Histogram_Ptr Histogram);
int Get_Num_of_psum_tuples(Psum_Ptr);
Psum_Tuple_Ptr Get_psum_Array(Psum_Ptr);
void Delete_Psum(Psum_Ptr);
void Print_Psum(Psum_Ptr);

#endif //SORT_JOIN_RELATION_CREATOR_H
