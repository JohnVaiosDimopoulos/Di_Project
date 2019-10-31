#include "Initializer/Argument_Manager.h"
#include "Initializer/Data_Table/Data_Table.h"
#include "Pre_Processing/Pre_Processor.h"
#include "Initializer/Table_Initializer.h"
#include "Histogram/Histogram.h"

int main(int argc,char** argv){
  Data_Table_Ptr Data_Table_1,Data_Table_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(&Data_Table_1,&Data_Table_2,Manager);
  Print_Table(Data_Table_1);
  Print_Table(Data_Table_2);

  RelationPtr Relation1 = Get_Relation(Data_Table_1);
  RelationPtr Relation2 = Get_Relation(Data_Table_2);
  Print_Relation(Relation1);
  Print_Relation(Relation2);

  Histogram_Ptr Histogram1 = Create_Histogram(Relation1);
  Histogram_Ptr Histogram2 = Create_Histogram(Relation2);
  Print_Histogram(Histogram1);
  Print_Histogram(Histogram2);

  Delete_ArgManager(Manager);
  Delete_Histogram(Histogram1);
  Delete_Histogram(Histogram2);

  Delete_Relation(Relation1);
  Delete_Relation(Relation2);

  Delete_Data_Table(Data_Table_1);
  Delete_Data_Table(Data_Table_2);

  return 0;
}
