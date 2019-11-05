#include "string.h"
#include "Relation_Sorting.h"
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void swap(uint64_t* a, uint64_t* b) { 
	uint64_t t = *a; 
	*a = *b; 
	*b = t; 
} 
  
int partition (RelationPtr A, int low, int high) { 
	uint64_t pivot = A->tuples[high].element;    // pivot 
	int i = (low - 1);  // Index of smaller element 
	
	for (int j = low; j <= high- 1; j++) { 
		// If current element is smaller than the pivot 
		if (A->tuples[j].element < pivot) { 
			i++;    // increment index of smaller element 
			swap(&A->tuples[j].element , &A->tuples[i].element); 
			swap(&A->tuples[j].row_id , &A->tuples[i].row_id); 
		}
	} 
	swap(&A->tuples[high].element , &A->tuples[i + 1].element); 
	swap(&A->tuples[high].row_id , &A->tuples[i + 1].row_id); 
	return (i + 1); 
} 
  
void quickSort(RelationPtr A, int low, int high) { 
	if (low < high) { 
		/* pi is partitioning index, arr[p] is now 
		   at right place */
		int pi = partition(A, low, high); 
		
		// Separately sort elements before 
		// partition and after partition 
		quickSort(A, low, pi - 1); 
		quickSort(A, pi + 1, high); 
	} 
} 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


static void Sort_Relation(RelationPtr Relation, RelationPtr R, int byte) {
//  printf("\n\n\nSORT BY %d\n", byte);

  if(byte < 1 ) {
    return;
  }

  uint64_t size = sizeof(*(Relation->tuples)) * Relation->num_of_tuples;
  if(size < 64000) {
//      printf("SMALL ENOUGH: %llu\n\n", size);
      quickSort(Relation, 0, Relation->num_of_tuples - 1);
	  return;
  }

//  printf("\t\t\t\tPASS: %llu\n\n", size);

  Histogram_Ptr Histogram = Get_Histogram(Relation, byte);
  Psum_Ptr Psum = Get_Psum(Histogram);
//  Print_Histogram(Histogram);
//  Print_Psum(Psum);

//  Print_Relation(Relation);
  Copy_Relation(Relation, R, Psum, byte);
  memcpy(Relation->tuples, R->tuples, Relation->num_of_tuples * sizeof(struct Tuple));

  for(int bucket = 0; bucket < PSUM_SIZE; bucket++){
    if(Get_psum_Array(Psum)[bucket]==-1)
      continue;

    RelationPtr New_Relation = Create_Relation_with_given_array(
        Get_Histogram_Array(Histogram)[bucket], &(Relation->tuples[Get_psum_Array(Psum)[bucket]]));
    Sort_Relation(New_Relation, R, byte - 1);
    New_Relation->tuples = NULL;
    Delete_Relation(New_Relation);
  }

  Delete_Psum(Psum);
  Delete_Histogram(Histogram);
}


void Sort(RelationPtr Relation){
  RelationPtr R;
  R = Create_Relation(Relation->num_of_tuples);

  Sort_Relation(Relation, R, 8);
  //Print_Relation(Relation);
  Delete_Relation(R);
}

