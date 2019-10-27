#include "Table_Initializer.h"
#include "../Util/Utilities.h"

static void Initialize_Table(Data_Table_Ptr* Table,const char* filename){
  FILE* File;
  if(Open_File_for_Read(&File,filename)){
    *Table=Set_up_Data_Table(File);
    fclose(File);
  }
}

void Initialize(Data_Table_Ptr* Table_1, Data_Table_Ptr* Table_2, Arg_Manager_Ptr Manager){
  Table_FileNames_Ptr File_Names = Get_File_Names(Manager);
  Initialize_Table(Table_1,Get_FileName_1(File_Names));
  Initialize_Table(Table_2,Get_FileName_2(File_Names));
}
