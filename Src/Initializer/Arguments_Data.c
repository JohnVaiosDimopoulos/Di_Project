#include "Arguments_Data.h"
#include <stdlib.h>
#include "../Util/Utilities.h"

struct Arguments_Data{
  char* File_Name_1;
  char* File_Name_2;

};

Argument_Data_Ptr Create_Argument_Data(const char * File_Name_1, const char * File_Name_2) {
  Argument_Data_Ptr Data = (Argument_Data_Ptr)malloc(sizeof(struct Arguments_Data));
  Data->File_Name_1= Allocate_and_Copy_Str(File_Name_1);
  Data->File_Name_2= Allocate_and_Copy_Str(File_Name_2);
  return Data;
}

void Delete_Argument_Data(Argument_Data_Ptr Data){
  free(Data->File_Name_1);
  free(Data->File_Name_2);
  free(Data);
}

const char* Get_FileName_1(Argument_Data_Ptr Data){
  return Data->File_Name_1;
}

const char* Get_FileName_2(Argument_Data_Ptr Data){
  return Data->File_Name_2;
}


