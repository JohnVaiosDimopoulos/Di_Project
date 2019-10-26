#ifndef SORT_JOIN_DATA_TABLE_H
#define SORT_JOIN_DATA_TABLE_H

#include <stdio.h>
#include <stdint.h>
typedef struct Data_Table* Data_Table_Ptr;

Data_Table_Ptr Create_Data_Table(int,int,int);
Data_Table_Ptr Set_up_Data_Table(FILE *File_ptr);
int Get_Num_of_raws(Data_Table_Ptr);
int Get_Num_of_columns(Data_Table_Ptr);
void Delete_Data_Table(Data_Table_Ptr);

//For exhibition purposes only
void Print_Table(Data_Table_Ptr);

#endif //SORT_JOIN_DATA_TABLE_H
