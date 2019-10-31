
#ifndef SORT_JOIN_ARGUMENTS_DATA_H
#define SORT_JOIN_ARGUMENTS_DATA_H

typedef struct Arguments_Data* Argument_Data_Ptr;

Argument_Data_Ptr Create_Argument_Data(const char *, const char *);
const char* Get_FileName_1(Argument_Data_Ptr);
const char* Get_FileName_2(Argument_Data_Ptr);
void Delete_Argument_Data(Argument_Data_Ptr);

#endif //SORT_JOIN_ARGUMENTS_DATA_H
