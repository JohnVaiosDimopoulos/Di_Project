#include <gtest/gtest.h>
#include "../../../Initializer/Data_Table/Data_Table.c"

class Data_Table_Tests : public ::testing::Test {
 public:

  int num_of_elements = 10;
  int num_of_rows = 5;
  int num_of_columns = 2;
  FILE* Input_File_1,*Input_File_2;

 protected:
 protected:
  virtual void TearDown() {
   fclose(Input_File_1);
   fclose(Input_File_2);
  }

  virtual void SetUp() {
    Input_File_1=fopen("./Test_Files/Test_Table_1", "r");
    Input_File_2=fopen("./Test_Files/Test_Table_2", "r");
  }


};

TEST_F(Data_Table_Tests,Create_Data_Table_Corect){
  Data_Table_Ptr Table =Create_Data_Table(
      num_of_elements,
      num_of_rows,
      num_of_columns);

  ASSERT_EQ(Table->num_of_columns,num_of_columns);
  ASSERT_EQ(Table->num_of_elements,num_of_elements);
  ASSERT_EQ(Table->num_of_rows, num_of_rows);
}

TEST_F(Data_Table_Tests,Create_Data_Table_Wrong) {
  Data_Table_Ptr Table = Create_Data_Table(
      0,
      num_of_rows,
      num_of_columns);

  ASSERT_EQ(nullptr,Table);
}

TEST_F(Data_Table_Tests,Count_Array_elements_Table_1){
  Table_Size Size_Test  = {4,3,12};

  Table_Size Size_result = Count_Array_elements(Input_File_1);
  ASSERT_EQ(Size_result.Table_elements,Size_Test.Table_elements);

  ASSERT_EQ(Size_result.Table_rows,Size_Test.Table_rows);
  ASSERT_EQ(Size_result.Table_columns,Size_Test.Table_columns);
}

TEST_F(Data_Table_Tests,Count_Array_elements_Table_2){
  Table_Size Size_Test  = {3,2,6};

  Table_Size Size_result = Count_Array_elements(Input_File_2);
  ASSERT_EQ(Size_result.Table_elements,Size_Test.Table_elements);

  ASSERT_EQ(Size_result.Table_rows,Size_Test.Table_rows);
  ASSERT_EQ(Size_result.Table_columns,Size_Test.Table_columns);
}

TEST_F(Data_Table_Tests,Fill_Array_Check_Elements_Table_1){

uint64_t Array_Test_Elements[] = {1,2,3,2,3,3,3,3,4,4,2,1};
uint64_t Array_Test_Row_Id[] = {1,1,1,2,2,2,3,3,3,4,4,4};

Table_Size Size = {4,3,12};
Data_Table_Ptr Table = Create_Data_Table(Size.Table_elements,Size.Table_rows,Size.Table_columns);

Fill_array_from_file(Table, Input_File_1);
for(int i = 0;i<Size.Table_elements;i++){
  ASSERT_EQ(Table->Array[i].element,Array_Test_Elements[i]);
  ASSERT_EQ(Table->Array[i].row_id,Array_Test_Row_Id[i]);
  }
}

TEST_F(Data_Table_Tests,Fill_Array_Check_Elements_Table_2){

uint64_t Array_Test_Elements[] = {1,2,1,6,3,2};
uint64_t Array_Test_Row_Id[] = {1,1,2,2,3,3};

Table_Size Size = {3,2,6};
Data_Table_Ptr Table = Create_Data_Table(Size.Table_elements,Size.Table_rows,Size.Table_columns);

Fill_array_from_file(Table, Input_File_2);
for(int i = 0;i<Size.Table_elements;i++){
  ASSERT_EQ(Table->Array[i].element,Array_Test_Elements[i]);
  ASSERT_EQ(Table->Array[i].row_id,Array_Test_Row_Id[i]);
  }
}

TEST_F(Data_Table_Tests,Traspose_Test_Table_1) {
  uint64_t Transposed_Array[] = {1, 2, 3, 4, 2, 3, 3, 2, 3, 3, 4, 1};
  Table_Size Size = {4, 3, 12};
  Data_Table_Ptr Table = Create_Data_Table(Size.Table_elements, Size.Table_rows, Size.Table_columns);
  Fill_array_from_file(Table, Input_File_1);

  Transpose_Array(Table);
  for (int i = 0; i < Size.Table_elements; i++) {
    ASSERT_EQ(Table->Array[i].element, Transposed_Array[i]);
  }
}

TEST_F(Data_Table_Tests,Traspose_Test_Table_2) {
  uint64_t Transposed_Array[] = {1, 1, 3, 2, 6, 2};
  Table_Size Size = {3, 2, 6};
  Data_Table_Ptr Table = Create_Data_Table(Size.Table_elements, Size.Table_rows, Size.Table_columns);
  Fill_array_from_file(Table, Input_File_2);

  Transpose_Array(Table);
  for (int i = 0; i < Size.Table_elements; i++) {
    ASSERT_EQ(Table->Array[i].element, Transposed_Array[i]);
  }
}

TEST_F(Data_Table_Tests,SetUp_test){
  uint64_t Transposed_Array[] = {1, 2, 3, 4, 2, 3, 3, 2, 3, 3, 4, 1};
  Table_Size Size_Test  = {4,3,12};


  Data_Table_Ptr Table = Set_up_Data_Table(Input_File_1);
  ASSERT_EQ(Table->num_of_elements,12);
  ASSERT_EQ(Table->num_of_rows,3);
  ASSERT_EQ(Table->num_of_columns,4);
  for (int i = 0; i < Size_Test.Table_elements; i++) {
    ASSERT_EQ(Table->Array[i].element, Transposed_Array[i]);
  }

}
