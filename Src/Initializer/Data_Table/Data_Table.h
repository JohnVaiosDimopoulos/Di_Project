#ifndef SORT_JOIN_DATA_TABLE_H
#define SORT_JOIN_DATA_TABLE_H

#include <stdio.h>
typedef struct Data_Table* Data_Table_Ptr;

Data_Table_Ptr Create_Data_Table(int,int,int);
void Fill_array(Data_Table_Ptr,FILE*);
int Get_Num_of_raws(Data_Table_Ptr);
int Get_Num_of_columns(Data_Table_Ptr);
void Delete_Data_Table(Data_Table_Ptr);

#endif //SORT_JOIN_DATA_TABLE_H
