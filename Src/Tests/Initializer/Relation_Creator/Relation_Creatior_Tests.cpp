#include <gtest/gtest.h>
#include "../../../Initializer/Relation_Creator/Relation_Creator.c"

class Relation_Creator_Tests : public ::testing::Test {
 public:


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

TEST_F(Relation_Creator_Tests,Create_Relation){
  int num_of_elements = 10;
  RelationPtr Relation= Create_Relation(num_of_elements);

  ASSERT_EQ(Relation->num_of_tuples,num_of_elements);
}

TEST_F(Relation_Creator_Tests,Create_Relation_Wrong) {
 RelationPtr Relation = Create_Relation(0);

  ASSERT_EQ(nullptr,Relation);
}

TEST_F(Relation_Creator_Tests,Count_File_elements_File_1){

  int num_of_elements = 7;
  ASSERT_EQ(num_of_elements,Count_File_elements(Input_File_1));

}

TEST_F(Relation_Creator_Tests,Count_File_elements_File_2){
  int num_of_elements = 3;
  ASSERT_EQ(num_of_elements,Count_File_elements(Input_File_2));
}

TEST_F(Relation_Creator_Tests,Fill_Array_Check_Elements_Table_1){

uint64_t Array_Test_Elements[] = {1,2,3,4,5,6,7};
uint64_t Array_Test_Row_Id[] = {1,2,3,4,5,6,7};

int num_of_elements=7;
RelationPtr Relation = Create_Relation(num_of_elements);

Fill_array_from_file(Relation, Input_File_1);
for(int i = 0;i<num_of_elements;i++){
  ASSERT_EQ(Relation->tuples[i].element,Array_Test_Elements[i]);
  ASSERT_EQ(Relation->tuples[i].row_id,Array_Test_Row_Id[i]);
  }
}

TEST_F(Relation_Creator_Tests,Fill_Array_Check_Elements_Table_2){

  uint64_t Array_Test_Elements[] = {1,2,3};
  uint64_t Array_Test_Row_Id[] = {3,4,8};

  int num_of_elements=3;
  RelationPtr Relation = Create_Relation(num_of_elements);

  Fill_array_from_file(Relation, Input_File_2);
  for(int i = 0;i<num_of_elements;i++){
    ASSERT_EQ(Relation->tuples[i].element,Array_Test_Elements[i]);
    ASSERT_EQ(Relation->tuples[i].row_id,Array_Test_Row_Id[i]);
  }
}

TEST_F(Relation_Creator_Tests,SetUp_test){

  uint64_t Elements[]={1,2,3,4,5,6,7};

  int num_of_elements=7;
  RelationPtr Relation = Set_up_Relation(Input_File_1);
  Print_Relation(Relation);
  ASSERT_EQ(Relation->num_of_tuples,7);
  for (int i = 0; i < num_of_elements; i++) {
    ASSERT_EQ(Relation->tuples[i].element, Elements[i]);
  }
}

