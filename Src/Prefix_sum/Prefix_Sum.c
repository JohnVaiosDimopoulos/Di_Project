#include <stdlib.h>
#include "../Initializer/Relation_Creator/Relation_Creator.h"
#include "../Basis_Structs/Tuple.h"
#include "../Basis_Structs/Relation.h"
#include "../Histogram/Histogram.h"
#include "../Basis_Structs/Hist_Tuple.h"
#include "Prefix_Sum.h"
#include "../Basis_Structs/Psum_Tuple.h"
#include "../Util/Utilities.h"


struct Psum{
  int num_of_elements;
  int num_of_tuples;
  Psum_Tuple_Ptr Array;
};

void Fill_Psum(Histogram_Ptr Histogram, Psum_Ptr Psum){
  (Psum->Array[0]).sum = 0;
  (Psum->Array[0]).value = Get_Hist_Array(Histogram)[0].value;
  for(int i = 1; i < Get_Num_of_hist_tuples(Histogram); i++) {
    (Psum->Array[i]).value = Get_Hist_Array(Histogram)[i].value;
    (Psum->Array[i]).sum = Get_Hist_Array(Histogram)[i - 1].quantity + (Psum->Array[i - 1]).sum;
  }
}

Psum_Ptr Create_Psum(Histogram_Ptr Histogram) {

  Psum_Ptr Psum = (Psum_Ptr)malloc(sizeof(struct Psum));

//  printf("diff = %d\n\n", num_of_tuples);
  Psum->num_of_tuples = Get_Num_of_hist_tuples(Histogram);

  Psum->Array = Allocate_Array(Psum->num_of_tuples);
  if(Psum->Array==NULL)
    return NULL;

  Fill_Psum(Histogram, Psum);

  return Psum;
}

void Print_Psum(Psum_Ptr Psum){
  for(int r =0; r < Psum->num_of_tuples; r++)
    printf("value: %llu, sum: %llu\n",(Psum->Array[r]).value, (Psum->Array[r]).sum);
  printf("\n\n");
}

int Get_Num_of_psum(Psum_Ptr Psum){
  return Psum->num_of_tuples;
}

int Get_Num_of_psum_elements(Psum_Ptr Psum){
  return Psum->num_of_elements;
}

Psum_Tuple_Ptr Get_psum_Array(Psum_Ptr Psum){
  return Psum->Array;
}

void Delete_Psum(Psum_Ptr Psum){
//  Free_Array(Psum->Array);
  free(Psum->Array);
  free(Psum);
}

