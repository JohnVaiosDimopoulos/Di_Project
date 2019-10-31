#include <gtest/gtest.h>
#include "../../Initializer/Arguments_Data.c"



class Argument_Data_Tests: public testing::Test{
 public:
  const char* File_Name_1 = "File1";
  const char* File_Name_2 = "File2";
  const int Column_1 = 2;
  const int Column_2 = 1;
 protected:
  virtual void TearDown() {

  }
  virtual void SetUp() {

  }

};

TEST_F(Argument_Data_Tests, Create_Argument_Data){
  Argument_Data_Ptr Data = Create_Argument_Data(
      File_Name_1, File_Name_2);
  ASSERT_STREQ(File_Name_1, Data->File_Name_1);
  ASSERT_STREQ(File_Name_2, Data->File_Name_2);

}

TEST_F(Argument_Data_Tests, Getters_Test){
  Argument_Data_Ptr Data = Create_Argument_Data(
      File_Name_1, File_Name_2);
  ASSERT_STREQ(File_Name_1,Get_FileName_1(Data));
  ASSERT_STREQ(File_Name_2,Get_FileName_2(Data));

}

