#include "Table_Files.h"
#ifndef SORT_JOIN_ARGUMET_MANAGER_H
#define SORT_JOIN_ARGUMET_MANAGER_H

typedef struct Arg_Manager* Arg_ManagerPtr;
Table_FileNames_Ptr Get_File_Names(Arg_ManagerPtr);
Arg_ManagerPtr Create_ArgManager(int, char**);
void Delete_ArgManager(Arg_ManagerPtr);

#endif //SORT_JOIN_ARGUMET_MANAGER_H
