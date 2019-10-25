#include "Table_Files.h"
#include <stdlib.h>
#include "../Util/Utilities.h"

struct Table_Files{
  char* File_Name_1;
  char* File_Name_2;
};

Table_FileNames_Ptr Create_Table_Files(const char* File_Name_1 , const char* File_Name_2){
  Table_FileNames_Ptr Table_Files = (Table_FileNames_Ptr)malloc(sizeof(struct Table_Files));
  Table_Files->File_Name_1= Allocate_and_Copy_Str(File_Name_1);
  Table_Files->File_Name_2= Allocate_and_Copy_Str(File_Name_2);
  return Table_Files;
}

void Delete_Table_Files(Table_FileNames_Ptr TableFiles){
  free(TableFiles->File_Name_2);
  free(TableFiles->File_Name_1);
  free(TableFiles);
}

const char* Get_FileName_1(Table_FileNames_Ptr Table_FileNames){
  return Table_FileNames->File_Name_1;
}

const char* Get_FileName_2(Table_FileNames_Ptr Table_FileNames){
  return Table_FileNames->File_Name_2;
}