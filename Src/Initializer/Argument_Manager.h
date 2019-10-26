#include "Table_Files.h"
#ifndef SORT_JOIN_ARGUMET_MANAGER_H
#define SORT_JOIN_ARGUMET_MANAGER_H

typedef struct Arg_Manager* Arg_Manager_Ptr;
Table_FileNames_Ptr Get_File_Names(Arg_Manager_Ptr);
Arg_Manager_Ptr Create_ArgManager(int, char**);
void Delete_ArgManager(Arg_Manager_Ptr);

#endif //SORT_JOIN_ARGUMET_MANAGER_H
