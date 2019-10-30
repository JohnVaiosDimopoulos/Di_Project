#include "Table_Initializer.h"
#include "../Util/Utilities.h"

static void Initialize_Table(Data_Table_Ptr* Table,const char* filename, const int Join_Column_num){
  FILE* File;
  if(Open_File_for_Read(&File,filename)){
    *Table=Set_up_Data_Table(File,Join_Column_num);
    fclose(File);
  }
}

void Initialize(Data_Table_Ptr* Table_1, Data_Table_Ptr* Table_2, Arg_Manager_Ptr Manager){
  Argument_Data_Ptr Argument_Data = Get_Argument_Data(Manager);
  Initialize_Table(Table_1,Get_FileName_1(Argument_Data),Get_Join_Column_1(Argument_Data));
  Initialize_Table(Table_2,Get_FileName_2(Argument_Data),Get_Join_Column_2(Argument_Data));
  Delete_Argument_Data(Argument_Data);
}
