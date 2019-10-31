#include <stdlib.h>
#include "../Initializer/Data_Table/Data_Table.h"
#include "../Basis_Structs/Tuple.h"
#include "../Basis_Structs/Relation.h"
#include "Histogram.h"
#include "../Basis_Structs/Hist_Tuple.h"
#include "../Util/Utilities.h"


struct Histogram{
  int num_of_elements;
  int num_of_tuples;
  Hist_Tuple_Ptr Array;
};

int Count_Histogram_Rows(RelationPtr Relation) {
  
  int map[256] = {0};
  int different_values = 0;
  Tuple_Ptr Array = Relation->tuples;

  for(int c = 0; c < Relation->num_of_tuples; c++) {
    if(!map[Array[c].element])
      different_values++;
    map[Array[c].element]++;
  }

  return different_values;
}


void Fill_Histogram(RelationPtr Relation, Histogram_Ptr Histogram){
  uint64_t first_byte[Relation->num_of_tuples];
  int map[256] = {0};
  Tuple_Ptr Array = Relation->tuples;
  for(int c = 0; c < Relation->num_of_tuples; c++){
    uint64_t current_element = Array[c].element;
    first_byte[c] =  current_element >> (0 * 8); /*shift 0 bytes (in our case it will be >> 7 * 8)*/

    map[first_byte[c]]++;
  }
  int r = 0;
  for(int i = 0; i < 9; i++) {
    if(map[i]) {
      (Histogram->Array[r]).quantity = map[i];
      (Histogram->Array[r]).value = i;
	  r++;
	}
  }
}


Histogram_Ptr Create_Histogram(RelationPtr Relation) {
  Histogram_Ptr Histogram = (Histogram_Ptr)malloc(sizeof(struct Histogram));

  int num_of_tuples = Count_Histogram_Rows(Relation);
//  printf("diff = %d\n\n", num_of_tuples);
  Histogram->num_of_tuples = num_of_tuples;

  Histogram->Array=Allocate_Array(Histogram->num_of_tuples);
  if(Histogram->Array==NULL)
    return NULL;

  Fill_Histogram(Relation, Histogram);

  return Histogram;
}

void Print_Histogram(Histogram_Ptr Histogram){
  for(int r =0; r < Histogram->num_of_tuples; r++)
    printf("value: %llu, quantity: %llu\n",(Histogram->Array[r]).value, (Histogram->Array[r]).quantity);
  printf("\n\n");
}

int Get_Num_of_hist_tuples(Histogram_Ptr Histogram){
  return Histogram->num_of_tuples;
}

int Get_Num_of_hist_elements(Histogram_Ptr Histogram){
  return Histogram->num_of_elements;
}

Hist_Tuple_Ptr Get_Hist_Array(Histogram_Ptr Histogram){
  return Histogram->Array;
}

void Delete_Histogram(Histogram_Ptr Histogram){
  Free_Array(Histogram->Array);
  free(Histogram);
}

