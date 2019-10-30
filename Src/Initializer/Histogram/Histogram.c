#include <stdlib.h>
#include "../Data_Table/Data_Table.h"
#include "../Data_Table/Tuple.h"
#include "Histogram.h"
#include "Hist_Tuple.h"
#include "../../Util/Utilities.h"

struct Data_Table{
  int num_of_elements;
  int num_of_rows;
  int num_of_columns;
  Tuple_Ptr Array;
};

struct Histogram{
  int num_of_elements;
  int num_of_rows;
  Hist_Tuple_Ptr Array;
};

struct{
  int Table_rows;
  int Table_elements;
} typedef Table_Size;

int Count_Histogram_Rows(Data_Table_Ptr Table) {
  
  int map[256] = {0};
  int different_values = 0;

  for(int c = 0; c < Table->num_of_columns; c++) {
//    printf("%llu",(Table->Array + c)->element);
    if(!map[(Table->Array + c)->element])
      different_values++;
    map[(Table->Array + c)->element]++;
  }
//  printf("\ndiff = %d\n", different_values);

  return different_values;
}


void Fill_Histogram(Data_Table_Ptr Table, Histogram_Ptr Histogram){
  uint64_t first_byte[Table->num_of_columns];
  int map[256] = {0};
  for(int c = 0; c < Table->num_of_columns; c++){
    first_byte[c] = (Table->Array + c)->element >> (0 * 8); /*shift 0 bytes (in our case it will be >> 7 * 8)*/

//    printf("%llu ", first_byte[c]);
    map[first_byte[c]]++;
  }
//  printf("\n\n");
//  for(int i = 0; i < 9; i++) {
//    printf("first byte = %d: %d\n", i, map[i]);
//  }
  int r = 0;
  for(int i = 0; i < 9; i++) {
    if(map[i]) {
      (Histogram->Array + r)->quantity = map[i];
      (Histogram->Array + r)->value = i;
	  r++;
	}
  }
}


Histogram_Ptr Create_Histogram(Data_Table_Ptr Table) {
  Histogram_Ptr Histogram = (Histogram_Ptr)malloc(sizeof(struct Histogram));

  int num_of_rows = Count_Histogram_Rows(Table);
  Histogram->num_of_rows = num_of_rows;

  Histogram->Array=Allocate_Array(num_of_rows);
  if(Histogram->Array==NULL)
    return NULL;

  Fill_Histogram(Table, Histogram);

  Print_Histogram(Histogram);

  return Histogram;
}

void Print_Histogram(Histogram_Ptr Histogram){
  for(int r =0; r < Histogram->num_of_rows; r++)
    printf("value: %llu, quantity: %llu\n",(Histogram->Array + r)->value, (Histogram->Array + r)->quantity);
  printf("\n\n");
}

void Delete_Histogram(Histogram_Ptr Histogram){
  Free_Array(Histogram->Array);
  free(Histogram);
}

