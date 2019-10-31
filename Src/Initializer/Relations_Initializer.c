#include "Relations_Initializer.h"
#include "../Util/Utilities.h"

static void Initialize_Relation(RelationPtr *Relation, const char *filename) {
  FILE* File;
  if(Open_File_for_Read(&File,filename)){
    *Relation=Set_up_Relation(File);
    fclose(File);
  }
}

void Initialize(Arg_Manager_Ptr Manager, RelationPtr *Relation_1, RelationPtr *Relation_2) {
  Argument_Data_Ptr Argument_Data = Get_Argument_Data(Manager);
  Initialize_Relation(Relation_1, Get_FileName_1(Argument_Data));
  Initialize_Relation(Relation_2, Get_FileName_2(Argument_Data));
  Print_Relation(*Relation_1);
  Delete_Argument_Data(Argument_Data);
}
