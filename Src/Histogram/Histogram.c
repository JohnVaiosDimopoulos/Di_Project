#include <stdlib.h>
#include "../Initializer/Data_Table/Data_Table.h"
#include "../Basis_Structs/Tuple.h"
#include "Histogram.h"
#include "Hist_Tuple.h"
#include "../Util/Utilities.h"


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
  Tuple_Ptr Array = Get_Array(Table);

  for(int c = 0; c < Get_Num_of_columns(Table); c++) {
    if(!map[Array[c].element])
      different_values++;
    map[Array[c].element]++;
  }

  return different_values;
}


void Fill_Histogram(Data_Table_Ptr Table, Histogram_Ptr Histogram){
  uint64_t first_byte[Get_Num_of_columns(Table)];
  int map[256] = {0};
  Tuple_Ptr Array = Get_Array(Table);
  for(int c = 0; c < Get_Num_of_columns(Table); c++){
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
    printf("value: %lu, quantity: %lu\n",(Histogram->Array[r]).value, (Histogram->Array[r]).quantity);
  printf("\n\n");
}
