
#ifndef SORT_JOIN_TABLE_FILES_H
#define SORT_JOIN_TABLE_FILES_H

typedef struct Table_Files* Table_FileNames_Ptr;

Table_FileNames_Ptr Create_Table_Files(const char* , const char*);
const char* Get_FileName_1(Table_FileNames_Ptr);
const char* Get_FileName_2(Table_FileNames_Ptr);
void Delete_Table_Files(Table_FileNames_Ptr);

#endif //SORT_JOIN_TABLE_FILES_H
