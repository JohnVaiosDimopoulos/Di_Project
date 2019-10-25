#include <stdint.h>
#include "Data_Table.h"
#include "../../Util/Utilities.h"

struct Data_Table{
  int num_of_elements;
  int num_of_raws;
  int num_of_columns;
  uint64_t** Array;
};


Data_Table_Ptr Create_Data_Table(int num_of_elements,int num_of_raws,int num_of_columns){


}

void Fill_array(Data_Table_Ptr Table,FILE* File_Ptr){

}

int Get_Num_of_raws(Data_Table_Ptr Table){
  return Table->num_of_raws;
}

int Get_Num_of_columns(Data_Table_Ptr Table){
  return Table->num_of_columns;
}

void Delete_Data_Table(Data_Table_Ptr Table){


}
