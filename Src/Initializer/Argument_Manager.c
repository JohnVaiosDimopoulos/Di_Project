#include "Argument_Manager.h"
#include "../Util/Utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXPECTED_ARG_COUNT 5
#define FLAG_TABLE_1 "-T1"
#define FLAG_TABLE_2 "-T2"

struct Arg_Manager {
  int argc;
  char** argv;
};

static int Check_Arguments_Number(int argc) {
  if(argc!=EXPECTED_ARG_COUNT){
    printf("%s","Wrong Number of Arguments\n");
    return 0;
  }
  return 1;
}

/*
 * Gets through the arguments and stores the filenames into File_Name_1 and File_Name_2
 * Expected Format -T1 File1 -T2 File2
 * On success returns 1
 * On failure returns 0
 * */
static int Go_Through_Argv_And_Get_FileNames(Arg_Manager_Ptr Manager, char** File_Name_1, char** File_Name_2){

  for(int i=1;i<Manager->argc;i++){
    if(!strcmp(FLAG_TABLE_1,Manager->argv[i])){
      i++;
      *File_Name_1 = Allocate_and_Copy_Str(Manager->argv[i]);
    }
    else if(!strcmp(FLAG_TABLE_2,Manager->argv[i])){
      i++;
      *File_Name_2= Allocate_and_Copy_Str(Manager->argv[i]);
    }
    else{
      printf("%s","Wrong Argument format\n");
      return 0;
    }
  }
  return 1;
}


/* On success returns a Table_FileNames pointer with the names of the two files inside
 * On Failure returns NULL
 */
Table_FileNames_Ptr Get_File_Names(Arg_Manager_Ptr Manager){
  char* File_Name_1=NULL;
  char* File_Name_2=NULL;
  if(!Check_Arguments_Number(Manager->argc)){
    exit(-1);
  }


  if(!Go_Through_Argv_And_Get_FileNames(Manager,&File_Name_1,&File_Name_2))
    exit(-1);

  if(File_Name_1!=NULL && File_Name_2!=NULL)
    return Create_Table_Files(File_Name_1,File_Name_2);

  return NULL;
}


Arg_Manager_Ptr Create_ArgManager(int argc, char** argv){
 Arg_Manager_Ptr Manager =(Arg_Manager_Ptr)malloc(sizeof(struct Arg_Manager));
 Manager->argv=argv;
 Manager->argc=argc;
 return Manager;
}

void Delete_ArgManager(Arg_Manager_Ptr Manager){
  Manager->argv=NULL;
  free(Manager);
}
