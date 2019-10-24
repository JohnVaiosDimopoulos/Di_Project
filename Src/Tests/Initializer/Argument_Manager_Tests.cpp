#include <gtest/gtest.h>
#include "../../Initializer/Argument_Manager.c"
#include "../../Initializer/Table_Files.h"

class Arguments_Correct{

 public:
  int argc=5;
  char * argv[5];
  Arguments_Correct() {
    argv[0]="Program_Name";
    argv[1]="-T1";
    argv[2]="filename1";
    argv[3]="-T2";
    argv[4]="filename2";
  }
};

class Arguments_Wrong_num{
 public:
  int argc=2;
  char * argv[2];
  Arguments_Wrong_num() {
    argv[0]="Program_Name";
    argv[1]="-T1";
  }
};

class Arguments_Wrong_Flag{
 public:
  int argc=5;
  char * argv[5];
  Arguments_Wrong_Flag() {
    argv[0]="Program_Name";
    argv[1]="-T4";
    argv[2]="filename1";
    argv[3]="-T4";
    argv[4]="filename2";

  }
};

class Arg_Manager_Test:public testing::Test{
 protected:
  Arguments_Correct* Args_Correct;
  Arguments_Wrong_num* Args_Wrong_Num;
  Arguments_Wrong_Flag* Args_Wrong_Flag;


 protected:
  virtual void TearDown() {
    delete Args_Correct;
    delete Args_Wrong_Num;
    delete Args_Wrong_Flag;
  }
  virtual void SetUp() {
    Args_Correct= new Arguments_Correct();
    Args_Wrong_Num = new Arguments_Wrong_num();
    Args_Wrong_Flag = new Arguments_Wrong_Flag();
  }

};

TEST_F(Arg_Manager_Test,CreateManager){

Arg_ManagerPtr Manager = Create_ArgManager(Args_Correct->argc,Args_Correct->argv);
ASSERT_EQ(Args_Correct->argc,Manager->argc);
ASSERT_EQ(Args_Correct->argv[0],Manager->argv[0]);
ASSERT_EQ(Args_Correct->argv[1],Manager->argv[1]);
ASSERT_EQ(Args_Correct->argv[2],Manager->argv[2]);
ASSERT_EQ(Args_Correct->argv[3],Manager->argv[3]);
ASSERT_EQ(Args_Correct->argv[4],Manager->argv[4]);
}

TEST_F(Arg_Manager_Test, Check_Arguments_Number_Correct){

  Arg_ManagerPtr Manager = Create_ArgManager(Args_Correct->argc,Args_Correct->argv);
  ASSERT_EQ(1, Check_Arguments_Number(Manager->argc));
  Delete_ArgManager(Manager);
}

TEST_F(Arg_Manager_Test, Check_Arguments_Number_Wrong){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Wrong_Num->argc,Args_Wrong_Num->argv);
  ASSERT_EQ(0, Check_Arguments_Number(Manager->argc));
  Delete_ArgManager(Manager);
}

TEST_F(Arg_Manager_Test, Got_Through_Argv_Correct){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Correct->argc,Args_Correct->argv);
  char* File_Name_1;
  char* File_Name_2;
  ASSERT_EQ(1,Go_Through_Argv_And_Get_FileNames(Manager,&File_Name_1,&File_Name_2));
  ASSERT_STREQ("filename1",File_Name_1);
  ASSERT_STREQ("filename2",File_Name_2);
}

TEST_F(Arg_Manager_Test, Got_Through_Argv_Wrong){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Wrong_Flag->argc,Args_Wrong_Flag->argv);
  char* File_Name_1;
  char* File_Name_2;
  ASSERT_EQ(0,Go_Through_Argv_And_Get_FileNames(Manager,&File_Name_1,&File_Name_2));
}

TEST_F(Arg_Manager_Test, Get_File_Names_Correct){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Correct->argc,Args_Correct->argv);
  Table_FileNames_Ptr Table_FileNames = Get_File_Names(Manager);
  ASSERT_STREQ("filename1",Get_FileName_1(Table_FileNames));
  ASSERT_STREQ("filename2",Get_FileName_2(Table_FileNames));
}

TEST_F(Arg_Manager_Test,  Get_File_Names_Wrong_Flag){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Wrong_Flag->argc,Args_Wrong_Flag->argv);
  Table_FileNames_Ptr Table_FileNames = Get_File_Names(Manager);
  ASSERT_EQ(NULL,Table_FileNames);
}

TEST_F(Arg_Manager_Test, Get_File_Names_Wrong_Num){
  Arg_ManagerPtr Manager = Create_ArgManager(Args_Wrong_Num->argc,Args_Wrong_Num->argv);
  Table_FileNames_Ptr Table_FileNames = Get_File_Names(Manager);
  ASSERT_EQ(NULL,Table_FileNames);
}