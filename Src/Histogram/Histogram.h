#ifndef SORT_JOIN_DATA_HISTOGRAM_H
#define SORT_JOIN_DATA_HISTOGRAM_H

#include <stdio.h>
#include <stdint.h>
#include "../Basis_Structs/Hist_Tuple.h"

typedef struct Histogram* Histogram_Ptr;

Histogram_Ptr Get_Histogram(RelationPtr Relation, const int byte_to_check);
void Print_Histogram(Histogram_Ptr);
int Get_Num_of_hist_tuples(Histogram_Ptr);
Hist_Tuple_Ptr Get_Hist_Array(Histogram_Ptr);
void Delete_Histogram(Histogram_Ptr);

//Histogram_Ptr Set_up_Relation(FILE *File_ptr);

#endif //SORT_JOIN_RELATION_CREATOR_H
