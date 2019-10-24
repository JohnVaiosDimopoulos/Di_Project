#include <gtest/gtest.h>
#include "../../Initializer/Table_Files.c"



class Table_Files_Tests:public testing::Test{
 public:
  const char* File_Name_1 = "File1";
  const char* File_Name_2 = "File2";
 protected:
  virtual void TearDown() {

  }
  virtual void SetUp() {

  }

};

TEST_F(Table_Files_Tests, Create_Table_Files){
  Table_FileNames_Ptr Table_Files = Create_Table_Files(File_Name_1, File_Name_2);
  ASSERT_STREQ(File_Name_1,Table_Files->File_Name_1);
  ASSERT_STREQ(File_Name_2,Table_Files->File_Name_2);
}

TEST_F(Table_Files_Tests, Get_FileName_1){
  Table_FileNames_Ptr Table_Files = Create_Table_Files(File_Name_1, File_Name_2);
  ASSERT_STREQ(File_Name_1,Get_FileName_1(Table_Files));
}

TEST_F(Table_Files_Tests,Get_FileName_2){
  Table_FileNames_Ptr Table_Files = Create_Table_Files(File_Name_1, File_Name_2);
  ASSERT_STREQ(File_Name_2,Get_FileName_2(Table_Files));
}

