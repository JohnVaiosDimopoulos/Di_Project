#include <gtest/gtest.h>
#include "../../Prefix_sum/Prefix_Sum.c"
#include "../../Initializer/Relations_Initializer.h"

class Psum_Tests : public ::testing::Test {
 public:
  Histogram_Ptr  Histogram;
  const char* filename = "./Test_Files/Test_Table_Big";
 protected:
    virtual void TearDown() {
      free(Histogram);
    }

    virtual void SetUp() {
      RelationPtr Relation;
      Initialize_Relation(&Relation,filename);
      Histogram=Get_Histogram(Relation,1);
      free(Relation);
    }

};

TEST_F(Psum_Tests,Create_and_Initialize_Psum){
  int num_of_tuples = 2;
  Psum_Ptr Psum = Create_and_Initialize_Psum();
  for(int i =0;i<PSUM_SIZE;i++){
    ASSERT_EQ(-1,Psum->Array[i]);
  }

}


TEST_F(Psum_Tests,Fill_Psum){
  Psum_Ptr Psum=Create_and_Initialize_Psum();
  Fill_Psum(Histogram,Psum);
  ASSERT_EQ(0,Psum->Array[100]);
  ASSERT_EQ(200,Psum->Array[105]);
}


TEST_F(Psum_Tests,Get_Psum){
  Psum_Ptr Psum = Get_Psum(Histogram);
  ASSERT_EQ(0,Psum->Array[100]);

  ASSERT_EQ(200,Psum->Array[105]);

}