#include "Pre_Processor.h"
#include <stdlib.h>

static int Calculate_Column_elements(Data_Table_Ptr Table){
  int num_of_rows= Get_Num_of_rows(Table);
  int num_of_elements = Get_Num_of_elements(Table);
  return (int)num_of_elements/num_of_rows;
}

static RelationPtr Create_Relation(int elements_num){
  RelationPtr Relation = (RelationPtr)malloc(sizeof(Relation));
  if(Relation==NULL){
    printf("Memory Allocation error");
    exit(-1);
  }
  Relation->num_of_tuples=elements_num;
  return Relation;
}

RelationPtr Get_Relation(Data_Table_Ptr Table){
  int elements_in_column = Calculate_Column_elements(Table);
  int startIndex = (Get_Join_Column_Num(Table)-1)*elements_in_column;
  RelationPtr Relation = Create_Relation(elements_in_column);
  Relation->tuples=&Get_Array(Table)[startIndex];
  return Relation;
}

void Print_Relation(RelationPtr Relation){
  for(int i =0;i<Relation->num_of_tuples;i++){
    printf("(El:%lu,Raw:%d)\n",Relation->tuples[i].element,Relation->tuples[i].row_id);
  }
}

void Delete_Relation(RelationPtr Relation){
  Relation->tuples=NULL;
  free(Relation);
}

