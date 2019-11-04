#include "Initializer/Argument_Manager.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"
#include "Initializer/Relations_Initializer.h"
#include "Histogram/Histogram.h"
#include "Prefix_sum/Prefix_Sum.h"
#include "Relation_Sorting/Relation_Sorting.h"

int main(int argc,char** argv){
  RelationPtr Relation_1,Relation_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(Manager, &Relation_1, &Relation_2);

  Histogram_Ptr Histogram = Get_Histogram(Relation_1,8);
  Print_Histogram(Histogram);
  Psum_Ptr Psum = Get_Psum(Histogram);
  Print_Psum(Psum);
  
  RelationPtr Relation_new = Create_Relation(Get_Num_of_elements(Relation_1));
  Copy_Relation(Relation_1,Relation_new,Psum,8);
  Print_Relation(Relation_new);

//  Sort()

////////////////////////////////////
  Sort(Relation_1);
//  Sort(Relation_2);
////////////////////////////////////

  Delete_ArgManager(Manager);
  
  Delete_Relation(Relation_1);
  Delete_Relation(Relation_2);

  return 0;
}
