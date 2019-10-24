#include "String_Managing.h"
#include <string.h>
#include <stdlib.h>

char* Allocate_and_Copy(const char* source){
  char* New_String=(char*)malloc(sizeof(char)*(strlen(source)+1));
  strcpy(New_String,source);
  return New_String;
}

