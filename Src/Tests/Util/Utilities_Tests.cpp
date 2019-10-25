#include <gtest/gtest.h>
#include <cstdlib>
#include "../../Util/Utilities.c"

class Utilities_Tests : public ::testing::Test {
 public:
  const char* str = "Test String";

  //the root is in Src/Util
  const char* filename_relative = "../../Tests/Util/test_file";
  const char* filename_wrong = "./test_file";
  //this path depends on the machine you are in
  const char* filename_full_path =
      "/home/supergohan/Desktop/Di/7_th Semester/Di_Project/Src/Tests/Util/test_file";
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
  ASSERT_NE(nullptr,Allocate_Array(1,1));
}

TEST_F(Utilities_Tests,Allocate_Array_Zero_Input){
  ASSERT_EQ(nullptr,Allocate_Array(0,0));
}


TEST_F(Utilities_Tests, Free_Array){
  int Array_rows =1;
  int Array_columns = 1;
  uint64_t ** Array = Allocate_Array(Array_rows,Array_columns);
  ASSERT_EQ(1,Free_Array(Array,Array_columns));
}

TEST_F(Utilities_Tests,Free_Array_Nullptr){
  uint64_t ** Array = Allocate_Array(0,0);
  ASSERT_EQ(0,Free_Array(Array,0));
}