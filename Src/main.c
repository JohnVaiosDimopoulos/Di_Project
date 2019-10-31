#include "Initializer/Argument_Manager.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"
#include "Initializer/Relations_Initializer.h"
#include "Histogram/Histogram.h"
#include "Prefix_sum/Prefix_Sum.h"

int main(int argc,char** argv){
  RelationPtr Relation_1,Relation_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(Manager, &Relation_1, &Relation_2);
  Print_Relation(Relation_1);
  Print_Relation(Relation_2);

  Histogram_Ptr Histogram1 = Create_Histogram(Relation_1, 1);
  Histogram_Ptr Histogram2 = Create_Histogram(Relation_2, 1);
  Print_Histogram(Histogram1);
  Print_Histogram(Histogram2);

  Psum_Ptr Psum1 = Create_Psum(Histogram1);
  Psum_Ptr Psum2 = Create_Psum(Histogram2);
  Print_Psum(Psum1);
  Print_Psum(Psum2);
////////////////////////////////////

  Delete_ArgManager(Manager);

  Delete_Histogram(Histogram1);
  Delete_Histogram(Histogram2);

//  Delete_Relation(Relation_1);
//  Delete_Relation(Relation_2);



  return 0;
}
