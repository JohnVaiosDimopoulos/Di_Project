#include <gtest/gtest.h>
#include <cstdlib>
#include "../../Initializer/Data_Table/Tuple.h"
#include "../../Util/Utilities.c"

class Utilities_Tests : public ::testing::Test {
 public:
  const char* str = "Test String";

  //the root is in Src/Util
  const char* filename_relative = "./Test_Files/test_file";
  const char* filename_wrong = "./test_file";
  //this path depends on the machine you are in
  const char* filename_full_path =
      "/home/supergohan/Desktop/Di/7_th Semester/Di_Project/Src/Tests/Test_Files/test_file";
 protected:
  virtual void TearDown() {

  }
  virtual void SetUp() {

  }
};

TEST_F(Utilities_Tests, Allocate_and_Copy_Str){
  char* new_String= Allocate_and_Copy_Str(str);
  ASSERT_STREQ(new_String,"Test String");
}

TEST_F(Utilities_Tests,Open_File_for_Read_Relative){
  FILE* File_Ptr;
  ASSERT_EQ(1,Open_File_for_Read(&File_Ptr,filename_relative));
  fclose(File_Ptr);
}

TEST_F(Utilities_Tests, Open_File_for_Read_Full){
  FILE* File_Ptr;
  ASSERT_EQ(1,Open_File_for_Read(&File_Ptr,filename_full_path));
  fclose(File_Ptr);
}

TEST_F(Utilities_Tests,Open_File_for_Read_Wrong){
  FILE* File_Ptr;
  ASSERT_EQ(0,Open_File_for_Read(&File_Ptr,filename_wrong));
}

TEST_F(Utilities_Tests, Allocate_Array){
  ASSERT_NE(nullptr,Allocate_Array(3));
}

TEST_F(Utilities_Tests,Allocate_Array_Zero_Input){
  ASSERT_EQ(nullptr,Allocate_Array(0));
}

TEST_F(Utilities_Tests, Free_Array){
  int Array_elements=3;
  Tuple_Ptr Array = Allocate_Array(Array_elements);
  ASSERT_EQ(1, Free_Array(Array));
}

TEST_F(Utilities_Tests,Free_Array_Nullptr){
  Tuple_Ptr Array = Allocate_Array(0);
  ASSERT_EQ(0, Free_Array(Array));
}

TEST_F(Utilities_Tests, Generic_Swap_Test_int){
  int x = 2,y=3;
  ASSERT_EQ(0,generic_swap(&x,&y, sizeof(int)));
  ASSERT_EQ(3,x);
  ASSERT_EQ(2,y);
}

TEST_F(Utilities_Tests,Generic_Swap_Test_string){
  char str1[4]="hey",str2[4]="you";
  ASSERT_EQ(0,  generic_swap(str1,str2, sizeof(str1)));
  ASSERT_STREQ("you",str1);
  ASSERT_STREQ("hey",str2);

}

TEST_F(Utilities_Tests,Generic_Swap_Test_Tuple){
  Tuple_Ptr Tuple1 = (Tuple_Ptr)malloc(sizeof(Tuple));
  Tuple_Ptr Tuple2 = (Tuple_Ptr)malloc(sizeof(Tuple));
  Tuple1->element=2;Tuple1->row_id=1;
  Tuple2->element=5;Tuple2->row_id=2;

  ASSERT_EQ(0,  generic_swap(Tuple1,Tuple2, sizeof(Tuple)));
  ASSERT_EQ(Tuple1->element,5);
  ASSERT_EQ(Tuple1->row_id,2);
  ASSERT_EQ(Tuple2->element,2);
  ASSERT_EQ(Tuple2->row_id,1);
}

