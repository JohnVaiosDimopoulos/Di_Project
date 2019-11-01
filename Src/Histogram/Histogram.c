#include <stdlib.h>
#include "../Initializer/Relation_Creator/Relation_Creator.h"
#include "Histogram.h"
#include "../Basis_Structs/Hist_Tuple.h"
#include "../Util/Utilities.h"


struct Histogram{
  int num_of_tuples;
  Hist_Tuple_Ptr Array;
};

static int Count_Histogram_Rows(RelationPtr Relation, const int byte_to_check) {

  int map[256] = {0};
  int different_values = 0;
  Tuple_Ptr Array = Relation->tuples;

  uint8_t current;
  for(int c = 0; c < Relation->num_of_tuples; c++) {
    current = Array[c].element >> ((byte_to_check-1) * 8)& 0xff;
    if(!map[current]){
      different_values++;
    }

    map[current]++;
  }

  return different_values;
}

static void Fill_Histogram(RelationPtr Relation, Histogram_Ptr Histogram, const int byte_to_check) {

  uint8_t current_byte;
  int map[256] = {0};
  Tuple_Ptr Array = Relation->tuples;
  for(int c = 0; c < Relation->num_of_tuples; c++){
    uint8_t current_element = Array[c].element;
    current_byte =  current_element >> ((byte_to_check-1) * 8)& 0xff ;
    /*shift 0 bytes (in our case it will be >> 7 * 8)*/
    map[current_byte]++;
  }

  int r=0;
  for(int i = 0; i < 256; i++) {
    if(map[i]) {
      (Histogram->Array[r]).quantity = map[i];
      (Histogram->Array[r]).value = i;
      r++;
	}

  }
}

static Histogram_Ptr Create_Histogram(int histogram_rows_num){
  Histogram_Ptr Histogram = (Histogram_Ptr)malloc(sizeof(struct Histogram));
  Histogram->Array=(Hist_Tuple_Ptr)Allocate_Array(histogram_rows_num);
  Histogram->num_of_tuples=histogram_rows_num;
  if(Histogram->Array==NULL)
    exit(-1);
  return Histogram;
}



Histogram_Ptr Get_Histogram(RelationPtr Relation, const int byte_to_check) {

  if(byte_to_check>8){
    printf("byte_to_check out of range");
    exit(-1);
  }

  int histogram_rows_num = Count_Histogram_Rows(Relation, byte_to_check);
  Histogram_Ptr Histogram = Create_Histogram(histogram_rows_num);
  Fill_Histogram(Relation, Histogram, byte_to_check);

  return Histogram;
}

void Print_Histogram(Histogram_Ptr Histogram){
  for(int r =0; r < Histogram->num_of_tuples; r++)
    printf("value: %d, quantity: %llu\n",(Histogram->Array[r]).value, (Histogram->Array[r]).quantity);
  printf("\n\n");
}

int Get_Num_of_hist_tuples(Histogram_Ptr Histogram){
  return Histogram->num_of_tuples;
}

Hist_Tuple_Ptr Get_Hist_Array(Histogram_Ptr Histogram){
  return Histogram->Array;
}

void Delete_Histogram(Histogram_Ptr Histogram){
  free(Histogram->Array);
  free(Histogram);
}

