#include "Initializer/Argument_Manager.h"
#include "Initializer/Data_Table/Data_Table.h"
#include "Initializer/Table_Initializer.h"

int main(int argc,char** argv){
  Data_Table_Ptr Data_Table_1,Data_Table_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(&Data_Table_1,&Data_Table_2,Manager);
  Print_Table(Data_Table_1);
  Print_Table(Data_Table_2);

  Create_Histogram(Data_Table_1);
  Create_Histogram(Data_Table_2);
  Delete_ArgManager(Manager);
  Delete_Data_Table(Data_Table_1);
  Delete_Data_Table(Data_Table_2);

  return 0;
}
