#include <stdlib.h>
#include "Data_Table.h"
#include "../../Util/Utilities.h"

struct Data_Table{
  int num_of_elements;
  int num_of_rows;
  int num_of_columns;
  int Join_Column_num;
  Tuple_Ptr Array;
};

struct{
  int Table_rows;
  int Table_columns;
  int Table_elements;
} typedef Table_Size;

Data_Table_Ptr Create_Data_Table(int num_of_elements, int num_of_rows, int num_of_columns,int Join_Column_num){
  Data_Table_Ptr Table = (Data_Table_Ptr)malloc(sizeof(struct Data_Table));
  Table->num_of_columns=num_of_columns;
  Table->num_of_elements=num_of_elements;
  Table->num_of_rows=num_of_rows;
  Table->Join_Column_num=Join_Column_num;
  Table->Array=Allocate_Array(Table->num_of_elements);
  if(Table->Array==NULL)
    return NULL;
  return Table;

}

void Check_and_update_current_row(
  const int elements_per_row,
  int *elements_read_in_current_row,
  int *current_row) {

  if((*elements_read_in_current_row) ==elements_per_row){
    (*current_row)++;
    (*elements_read_in_current_row) =0;
  }
}

static Table_Size Init_Table_Size(){
  Table_Size Size;
  Size.Table_rows=0;
  Size.Table_columns=0;
  Size.Table_elements=0;
  return Size;
}

static void Fill_array_from_file(Data_Table_Ptr Table, FILE* File_Ptr){

  const int elements_per_row = (int) Table->num_of_elements/Table->num_of_rows;
  int elements_read_in_current_row = 0;
  int current_row=1;

  for(int i = 0;i<Table->num_of_elements;i++,elements_read_in_current_row++){

    Check_and_update_current_row(elements_per_row, &elements_read_in_current_row, &current_row);

    fscanf(File_Ptr,"%llu",&Table->Array[i].element);
    Table->Array[i].row_id=current_row;
  }

}

static Table_Size Count_Array_elements(FILE* File_Ptr){

 Table_Size Size = Init_Table_Size();

  int c=0;

  do {
    c = fgetc(File_Ptr);

    if(feof(File_Ptr))
      break ;

    if(c == '\n') {
      (Size.Table_rows)++;
    }

    else if(c != ' ')
      (Size.Table_elements)++;

  } while(1);



  (Size.Table_columns) = (int)(Size.Table_elements) / (Size.Table_rows);
  rewind(File_Ptr);
  return Size;
};

static void Initialize_ByteArray(const int Num_of_elements, uint8_t *byteArray) {
  for(int i = 0; i<Num_of_elements; i++)
    byteArray[i]=0;
}

static void Transpose_Array(Data_Table_Ptr Table){
  int Array_size = Table->num_of_elements-1;
  struct Tuple temp;
  int next;
  int cycleBegin;
  int i=1;
  uint8_t byteArray[Table->num_of_elements];
  Initialize_ByteArray(Table->num_of_elements, byteArray);
  byteArray[0]=byteArray[Array_size]=1;

  while (i<Array_size){
    cycleBegin=i;
    temp=Table->Array[i];

    do{
      next=(i*Table->num_of_rows)%Array_size;
      generic_swap(&temp,&Table->Array[next], sizeof(struct Tuple));
      byteArray[i]=1;
      i=next;
    }while (i!=cycleBegin);

    for(i=1;i<Array_size && byteArray[i];i++);
  }
}

Data_Table_Ptr Set_up_Data_Table(FILE* File_ptr,const int Join_Column_num){
  Table_Size size = Count_Array_elements(File_ptr);

  if(size.Table_columns<Join_Column_num || Join_Column_num<=0){
    printf("Wrong Join Column");
    exit(-1);
  }

  Data_Table_Ptr Table = Create_Data_Table(
      size.Table_elements,size.Table_rows,size.Table_columns,Join_Column_num);

  if(Table==NULL){
    printf("Error At Table creation");
    exit(-1);
  }

  Fill_array_from_file(Table,File_ptr);
//  Print_Table(Table);

  Transpose_Array(Table);
  generic_swap(&Table->num_of_rows,&Table->num_of_columns, sizeof(int));
  return Table;
}

int Get_Num_of_rows(Data_Table_Ptr Table){
  return Table->num_of_rows;
}

int Get_Num_of_columns(Data_Table_Ptr Table){
  return Table->num_of_columns;
}

int Get_Num_of_elements(Data_Table_Ptr Table){
  return Table->num_of_elements;
}

Tuple_Ptr Get_Array(Data_Table_Ptr Table){
  return Table->Array;
}

int Get_Join_Column_Num(Data_Table_Ptr Table){
  return Table->Join_Column_num;
}

void Delete_Data_Table(Data_Table_Ptr Table){
  Free_Array(Table->Array);
  free(Table);
}

void Print_Table(Data_Table_Ptr Table){
  for(int r =0; r<Table->num_of_rows;r++){
    for(int c =0; c<Table->num_of_columns;c++){
      printf("%llu", (Table->Array + r*Table->num_of_columns +c)->element);
//      printf("(%llu, %llu)", (Table->Array + r*Table->num_of_columns +c)->row_id, (Table->Array + r*Table->num_of_columns +c)->element);
    }
    printf("\n");
  }
  printf("\n\n");
}
