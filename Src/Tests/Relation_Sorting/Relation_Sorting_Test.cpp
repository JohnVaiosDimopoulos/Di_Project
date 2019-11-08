#include <gtest/gtest.h>
#include "../../Relation_Sorting/Relation_Sorting.c"
#include "../../Initializer/Relations_Initializer.h"


class Relation_Sorting_Test : public ::testing::Test {
 public:
  FILE* file;
  const char* filename = "./Test_Files/Test_Table_Big";
  const char* filenamae_small ="./Test_Files/Test_Table_3";
  RelationPtr Relation;
  RelationPtr Relation_sm;
  Psum_Ptr Psum;
  Histogram_Ptr Histogram;
 protected:

  virtual void SetUp() {
    file = fopen(filename,"r");
    Initialize_Relation(&Relation,filename);
    Histogram = Get_Histogram(Relation,8);
    Psum = Get_Psum(Histogram);

  }

  virtual void TearDown() {

    Delete_Relation(Relation);
    Delete_Psum(Psum);
    Delete_Histogram(Histogram);
  }
};


TEST_F(Relation_Sorting_Test,Get_index_map_test){

  int* map = Get_index_map(Psum);
  for(int i = 0 ;i<PSUM_SIZE;i++){
    ASSERT_EQ(Get_psum_Array(Psum)[i],map[i]);
  }

}

TEST_F(Relation_Sorting_Test,Find_Byte_Value){
  uint64_t element = Relation->tuples[0].element;
  uint8_t byte = Find_Byte_Value(element,8);
  ASSERT_EQ(byte,96);
}

TEST_F(Relation_Sorting_Test,Find_Byte_Value_wrong_byte){
  uint64_t element = Relation->tuples[0].element;
  ASSERT_EXIT(Find_Byte_Value(element,12),::testing::ExitedWithCode(255),"");
}

TEST_F(Relation_Sorting_Test,Copy_Relation){
  RelationPtr Buffer_Relation = Create_Relation(Get_Num_of_elements(Relation));
  uint64_t first_value = 1693931353023812964;
  uint64_t second_value = 6932635952696987497;
  Copy_Relation(Relation,Buffer_Relation,Psum,8);
  for(int i =0;i<200;i++)
    ASSERT_EQ(Buffer_Relation->tuples[i].element,first_value);
  for (int j = 200; j <Get_Num_of_elements(Relation) ; j++)
    ASSERT_EQ(Buffer_Relation->tuples[j].element,second_value);
}

TEST_F(Relation_Sorting_Test,Quick_sort){
  Initialize_Relation(&Relation_sm,filenamae_small);
  quickSort(Relation_sm,0,Relation_sm->num_of_tuples-1);

  ASSERT_EQ(Relation_sm->tuples[0].element,1);
  ASSERT_EQ(Relation_sm->tuples[1].element,2);
  ASSERT_EQ(Relation_sm->tuples[2].element,3);
  ASSERT_EQ(Relation_sm->tuples[3].element,5);
  ASSERT_EQ(Relation_sm->tuples[4].element,7);
  ASSERT_EQ(Relation_sm->tuples[5].element,11);
  ASSERT_EQ(Relation_sm->tuples[6].element,20);
}
