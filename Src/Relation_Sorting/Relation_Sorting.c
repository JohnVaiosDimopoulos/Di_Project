#include "string.h"
#include "Relation_Sorting.h"
#include "../Initializer/Relation_Creator/Relation_Creator.h"
#include "../Histogram/Histogram.h"
#include "../Prefix_sum/Prefix_Sum.h"
#include <stdlib.h>


static uint8_t Find_Byte_Value(uint64_t value, int byte_to_check) {

  if(byte_to_check > 8) {
    printf("byte_to_check out of range");
    exit(-1);
  }

  uint8_t byte = value >> ((byte_to_check - 1) * 8) & 0xff;
  return byte;
}

static int* Get_index_map(Psum_Ptr Psum){
  int* index_map=(int*)malloc(PSUM_SIZE* sizeof(int));
  int* Psum_Array=Get_psum_Array(Psum);
  memcpy(index_map, Psum_Array, sizeof(int)*PSUM_SIZE);
  return index_map;
}

void Copy_Relation(RelationPtr Source_rel,RelationPtr Dest_rel,Psum_Ptr Psum,const int byte_to_check) {

  int* index_map = Get_index_map(Psum);
  for(int i = 0; i < Source_rel->num_of_tuples; i++) {
    uint8_t byte = Find_Byte_Value(Source_rel->tuples[i].element, byte_to_check);
    int index = index_map[byte];
    Dest_rel->tuples[index].element = Source_rel->tuples[i].element;
    Dest_rel->tuples[index].row_id = Source_rel->tuples[i].row_id;
    index_map[byte]++;
  }
  free(index_map);
}

static void Sort_Relation(RelationPtr Relation, RelationPtr R, int byte) {
  printf("SORT\n");

  if(byte==0)
    return;

  Histogram_Ptr Histogram = Get_Histogram(Relation, byte);
  Psum_Ptr Psum = Get_Psum(Histogram);

  Copy_Relation(Relation, R, Psum, byte);
  memcpy(Relation->tuples, R->tuples, R->num_of_tuples * sizeof(struct Tuple));
//  Print_Relation(Relation);

  for(int bucket = 0; bucket < PSUM_SIZE; bucket++){
    if(Get_psum_Array(Psum)[bucket]==-1)
      continue;

    RelationPtr New_Relation = Create_Relation_with_given_array(
    Get_Histogram_Array(Histogram)[bucket], &(Relation->tuples[Get_psum_Array(Psum)[bucket]]));
    Print_Relation(New_Relation);
    Sort_Relation(New_Relation, R, byte - 1);
    New_Relation->tuples = NULL;
    Delete_Relation(New_Relation);
  }

//  Delete_Histogram(Histogram);
//  Delete_Psum(Psum);
}


void Sort(RelationPtr Relation){
  RelationPtr R;
  R = Create_Relation(Relation->num_of_tuples);

  Sort_Relation(Relation, R, 8);
  Delete_Relation(R);
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

