#include "Initializer/Argument_Manager.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"
#include "Initializer/Relations_Initializer.h"
#include "Relation_Sorting/Relation_Sorting.h"

int main(int argc,char** argv){
  RelationPtr Relation_1,Relation_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(Manager, &Relation_1, &Relation_2);

  
  Sort(Relation_1);
  Sort(Relation_2);

//  Print_Relation(Relation_1);
//  Print_Relation(Relation_2);

  //join
  Join(Relation_1, Relation_2);

 // printf("List Size = %d\n", LIST_SIZE);

  Delete_ArgManager(Manager);
  Delete_Relation(Relation_1);
  Delete_Relation(Relation_2);

  return 0;
}
