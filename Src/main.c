#include "Initializer/Argument_Manager.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"
#include "Initializer/Relations_Initializer.h"
#include "Histogram/Histogram.h"
#include "Prefix_sum/Prefix_Sum.h"
#include "New_Relation.h"

int main(int argc,char** argv){
  RelationPtr Relation_1,Relation_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(Manager, &Relation_1, &Relation_2);
  Print_Relation(Relation_1);
  Print_Relation(Relation_2);




  Histogram_Ptr Histogram1 = Get_Histogram(Relation_1, 1);
  Histogram_Ptr Histogram2 = Get_Histogram(Relation_2, 1);
  Print_Histogram(Histogram1);
  Print_Histogram(Histogram2);

  Psum_Ptr Psum1 = Get_Psum(Histogram1);
  Psum_Ptr Psum2 = Get_Psum(Histogram2);
  Print_Psum(Psum1);
  Print_Psum(Psum2);
////////////////////////////////////

  RelationPtr R1, R2;
  R1 = Create_Relation(Relation_1->num_of_tuples);
  R2 = Create_Relation(Relation_2->num_of_tuples);

  Copy_Relation(Relation_1, R1, Histogram1, Psum1);
  Copy_Relation(Relation_2, R2, Histogram2, Psum2);
  Print_Relation(R1);
  Print_Relation(R2);

////////////////////////////////////
  Delete_ArgManager(Manager);
  
  Delete_Psum(Psum1);
  Delete_Psum(Psum2);

  Delete_Histogram(Histogram1);
  Delete_Histogram(Histogram2);

  Delete_Relation(Relation_1);
  Delete_Relation(Relation_2);



  return 0;
}
