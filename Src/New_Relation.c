#include <stdlib.h>
#include "Basis_Structs/Relation.h"
#include "Util/Utilities.h"
#include "Histogram/Histogram.h"
#include "Prefix_sum/Prefix_Sum.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"

uint8_t Find_Byte_Value(uint64_t value, int byte_to_check) {
  if(byte_to_check > 8) {
    printf("byte_to_check out of range");
    exit(-1);
  }
  uint8_t byte = value >> ((byte_to_check - 1) * 8) & 0xff;
  return byte;
}

Hist_Tuple_Ptr Find_in_Histogram(Histogram_Ptr Histogram, uint8_t byte) {
  Hist_Tuple_Ptr tuple;
  tuple = Get_Hist_Array(Histogram);
  for(int i = 0; i < Get_Num_of_hist_tuples(Histogram); i++) {
    if(byte == tuple[i].value) {
	  tuple[i].quantity--;
      return &tuple[i];
	}
  }
  return NULL;
}

Psum_Tuple_Ptr Find_in_Psum(Psum_Ptr Psum, uint8_t byte) {
  Psum_Tuple_Ptr tuple;
  tuple = Get_psum_Array(Psum);
  for(int i = 0; i < Get_Num_of_psum_tuples(Psum); i++) {
    if(byte == tuple[i].value) {
      return &tuple[i];
	}
  }
  return NULL;
}
int Is_Last_Tupple(Psum_Ptr Psum, Psum_Tuple_Ptr psum_tuple) {
  Psum_Tuple_Ptr tuple;
  tuple = Get_psum_Array(Psum);
  int pos;
  for(int i = 0; i < Get_Num_of_psum_tuples(Psum); i++) {
    if(psum_tuple == tuple) {
       pos = i; 
	   break;
	}
  }
  if(pos + 1 == Get_Num_of_psum_tuples(Psum))
	  return 1;
  return 0;
}

void Copy_Relation(RelationPtr Source_rel, RelationPtr Dest_rel, Histogram_Ptr Histogram, Psum_Ptr Psum) {
//  printf("-->%llu\n\n", Dest_rel->num_of_tuples);
  for(int i = 0; i < Source_rel->num_of_tuples; i++) {
//    printf("(Row id: %llu),(Value: %llu)", Source_rel->tuples[i].row_id, Source_rel->tuples[i].element);
    uint8_t byte = Find_Byte_Value(Source_rel->tuples[i].element, 1);
//    printf(" byte = %hhu ", byte);
    Hist_Tuple_Ptr hist_tuple = Find_in_Histogram(Histogram, byte);
//    printf("\t-->FOUND %hhu %llu ", hist_tuple->value, hist_tuple->quantity);
    Psum_Tuple_Ptr psum_tuple = Find_in_Psum(Psum, byte);
	uint64_t offset = psum_tuple->sum;
//    printf("\toffset = %llu ", offset);
	uint64_t next_offset;
	if(!Is_Last_Tupple(Psum, psum_tuple))
//      printf("not last\n");
        next_offset = (psum_tuple + 1)->sum;
	else 
//      printf("last\n");
      next_offset = Source_rel->num_of_tuples;
//    printf("\tnext = %llu ", next_offset);
    
//    printf("placed in %llu\n", (next_offset - hist_tuple->quantity - 1));

    Dest_rel->tuples[next_offset - hist_tuple->quantity - 1].element = Source_rel->tuples[i].element;
    Dest_rel->tuples[next_offset - hist_tuple->quantity - 1].row_id = Source_rel->tuples[i].row_id;
  }
}
