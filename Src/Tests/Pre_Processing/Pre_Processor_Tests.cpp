#include <gtest/gtest.h>
#include <stdio.h>
#include "../../Pre_Processing/Pre_Processor.c"

class Pre_Processor_Tests : public ::testing::Test {
 public:
  Data_Table_Ptr Table;
 protected:
  virtual void SetUp() {
    FILE* Table_File = fopen("./Test_Files/Test_Table_1","r");
    Table = Set_up_Data_Table(Table_File,1);
  }
  virtual void TearDown() {
    Delete_Data_Table(Table);
  }
};


TEST_F(Pre_Processor_Tests,Calculate_Column_elements){
  ASSERT_EQ(4,Calculate_Column_elements(Table));
}

TEST_F(Pre_Processor_Tests,Create_Relation){
  RelationPtr Relation = Create_Relation(4);
  ASSERT_EQ(4,Relation->num_of_tuples);
}

TEST_F(Pre_Processor_Tests,Get_Relation){
  RelationPtr Relation = Get_Relation(Table);
  for(int i =0;i<Relation->num_of_tuples;i++){
      ASSERT_EQ(i+1,Relation->tuples[i].element);
      ASSERT_EQ(i+1,Relation->tuples[i].row_id);
  }
}


