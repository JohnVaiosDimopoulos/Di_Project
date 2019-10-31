#ifndef SORT_JOIN_DATA_HISTOGRAM_H
#define SORT_JOIN_DATA_HISTOGRAM_H

#include <stdio.h>
#include <stdint.h>
#include "../Basis_Structs/Hist_Tuple.h"

typedef struct Histogram* Histogram_Ptr;

Histogram_Ptr Create_Histogram(RelationPtr);
void Print_Histogram(Histogram_Ptr);
int Get_Num_of_hist_tuples(Histogram_Ptr);
int Get_Num_of_hist_elements(Histogram_Ptr);
Hist_Tuple_Ptr Get_Hist_Array(Histogram_Ptr);
void Delete_Histogram(Histogram_Ptr);
void Print_Histogram(Histogram_Ptr);

//Histogram_Ptr Set_up_Data_Table(FILE *File_ptr);

#endif //SORT_JOIN_DATA_TABLE_H
