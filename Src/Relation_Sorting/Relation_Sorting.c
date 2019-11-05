#include "string.h"
#include "Relation_Sorting.h"
#include "../Initializer/Relation_Creator/Relation_Creator.h"
#include "../Histogram/Histogram.h"
#include "../Prefix_sum/Prefix_Sum.h"
#include <stdlib.h>
#include "../Basis_Structs/Relation.h"
#include "../Util/Utilities.h"

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
	} else
	  tuple++;
  }
  if(pos + 1 == Get_Num_of_psum_tuples(Psum))
	  return 1;
  return 0;
}

void Copy_Relation(RelationPtr Source_rel, RelationPtr Dest_rel, Histogram_Ptr Histogram, Psum_Ptr Psum, int byte_to_check) {
//  printf("-->%llu %llu\n\n", *start, *end);
//  printf("-->%llu\n\n", Dest_rel->num_of_tuples);
  for(int i = 0; i < Source_rel->num_of_tuples; i++) {
//    printf("(Row id: %llu),(Value: %llu)", Source_rel->tuples[i].row_id, Source_rel->tuples[i].element);
    uint8_t byte = Find_Byte_Value(Source_rel->tuples[i].element, byte_to_check);
//    printf(" byte = %hhu ", byte);
    Hist_Tuple_Ptr hist_tuple = Find_in_Histogram(Histogram, byte);
//    printf("\t-->FOUND %hhu %llu ", hist_tuple->value, hist_tuple->quantity);
    Psum_Tuple_Ptr psum_tuple = Find_in_Psum(Psum, byte);
	uint64_t offset = psum_tuple->sum;
//    printf("\toffset = %llu ", offset);
	uint64_t next_offset;
	if(!Is_Last_Tupple(Psum, psum_tuple)) {
//      printf("not last\n");
        next_offset = (psum_tuple + 1)->sum;
    } else { 
  //    printf("last\n");
      next_offset = Source_rel->num_of_tuples;
	}
//    printf("\tnext = %llu ", next_offset);
    
//    printf("placed in %llu", (next_offset - hist_tuple->quantity - 1));
//    printf("\n");

    Dest_rel->tuples[next_offset - hist_tuple->quantity - 1].element = Source_rel->tuples[i].element;
    Dest_rel->tuples[next_offset - hist_tuple->quantity - 1].row_id = Source_rel->tuples[i].row_id;
//    printf("\tEND\n");
  }
}

void Sort_Relation(RelationPtr Relation, RelationPtr R, int byte) {
  printf("SORT\n");

  //CHECK IF REL FITS IN 64K

  Histogram_Ptr Histogram = Get_Histogram(Relation, byte);
  Print_Histogram(Histogram);

  Psum_Ptr Psum = Get_Psum(Histogram);
  Print_Psum(Psum);

  Copy_Relation(Relation, R, Histogram, Psum, byte);
  memcpy(Relation->tuples, R->tuples, R->num_of_tuples * sizeof(struct Tuple));
  Print_Relation(Relation);

  uint64_t start = 0;
  uint64_t end = R->num_of_tuples;

//  Copy_Relation_tuples(Relation, R->tuples, Histogram, Psum, byte, &Get_psum_Array(Psum)[0].sum, &Get_psum_Array(Psum)[1].sum);

//  //(for each bucket)
//int bucket = 0;
//  for(int bucket = 0; bucket < Get_Num_of_psum_tuples(Psum); bucket++){
//    RelationPtr New_Relation = Create_Relation_with_given_array(
//    Get_Hist_Array(Histogram)[bucket].quantity, &(Relation->tuples[Get_psum_Array(Psum)[bucket].sum]));
//    Sort_Relation(New_Relation, R, byte - 1);
//    Print_Relation(New_Relation);
//    New_Relation->tuples = NULL;
//    Delete_Relation(New_Relation);
//  }

  Delete_Psum(Psum);
  Delete_Histogram(Histogram);
}


void Sort(RelationPtr Relation){
  RelationPtr R;
  R = Create_Relation(Relation->num_of_tuples);

  Sort_Relation(Relation, R, 8);
  
  R->tuples=NULL;
  Delete_Relation(R);
//  Print_Relation(Relation);
}
 
//AFHNW TA COMMENTS SOU EDW

//  * Histogram_Prt Histogram = Get_Histogram(Relation,byte);
// Psum_Ptr Psum = Get_Psum(Histogram);
// Sort R based on given byte to R'
// memcpy(R->array,R'->array,array_size)
//
//
// (for each bucket)
// for(int i =0;i<Psum->num_of_elements;i++){
// New_Relation = Create_Relation_with_given_array(
// (size)Histogram->Array[i].quantity,(bicket_start)Relation->Array[Psum->Array[i].sum]);
// Sort_Relation(New_Relation,Relation',byte-1);
// New_Relation->Array=NULL;
// Delete(New_Relation);
// }
// Delete(Psum);
// Delete(Histogram);

