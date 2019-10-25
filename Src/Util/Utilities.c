#include "Utilities.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* Allocate_and_Copy_Str(const char* source){
  char* New_String=(char*)malloc(sizeof(char)*(strlen(source)+1));
  strcpy(New_String,source);
  return New_String;
}

int Open_File_for_Read(FILE** File_Ptr,const char* File_Name){
  if(((*File_Ptr)=fopen(File_Name,"r"))!=NULL)
    return 1;
  printf("Wrong file path\n");
  return 0;
}

uint64_t ** Allocate_Array(int Array_rows,int Array_columns){

  if(Array_rows==0 || Array_columns==0)
    return NULL;

  uint64_t ** New_Array =(uint64_t**) malloc(Array_rows* sizeof(uint64_t*));

  if(New_Array==NULL){
    printf("Memory Allocation Failed\n");
    return NULL;
  }

  for(int i = 0; i < Array_rows; i++){
    New_Array[i] =(uint64_t*)malloc(Array_columns * sizeof(uint64_t));
    if(New_Array[i]==NULL){
      printf("Memory Allocation Failed\n");
      return NULL;
    }
  }
  return New_Array;
}

int Free_Array(uint64_t** Array ,int Array_columns){

  if(Array==NULL)
    return 0;

  for(int i =0;i<Array_columns;i++)
    free(Array[i]);
  free(Array);
  return 1;

}