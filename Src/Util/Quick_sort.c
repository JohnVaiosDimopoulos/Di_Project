
#include "Quick_sort.h"
#include "Utilities.h"

int partition (RelationPtr A, int low, int high) {
  uint64_t pivot = A->tuples[high].element;    // pivot
  int i = (low - 1);  // Index of smaller element

  for (int j = low; j <= high- 1; j++) {

    // If current element is smaller than the pivot
    if (A->tuples[j].element < pivot) {
      i++;    // increment index of smaller element
      generic_swap(&A->tuples[j].element , &A->tuples[i].element, sizeof(uint64_t));
      generic_swap(&A->tuples[j].row_id , &A->tuples[i].row_id,sizeof(uint64_t));
    }
  }
  generic_swap(&A->tuples[high].element , &A->tuples[i + 1].element,sizeof(uint64_t));
  generic_swap(&A->tuples[high].row_id , &A->tuples[i + 1].row_id,sizeof(uint64_t));
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