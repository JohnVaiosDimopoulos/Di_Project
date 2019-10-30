#ifndef SORT_JOIN_DATA_HISTOGRAM_H
#define SORT_JOIN_DATA_HISTOGRAM_H

#include <stdio.h>
#include <stdint.h>

typedef struct Histogram* Histogram_Ptr;

Histogram_Ptr Create_Histogram(Data_Table_Ptr);
void Print_Histogram(Histogram_Ptr);
//Histogram_Ptr Set_up_Data_Table(FILE *File_ptr);
//int Get_Num_of_raws(Histogram_Ptr);
//void Delete_Histogram(Histogram_Ptr);
//
////For exhibition purposes only
//void Print_Histogram(Histogram_Ptr);

#endif //SORT_JOIN_DATA_TABLE_H
