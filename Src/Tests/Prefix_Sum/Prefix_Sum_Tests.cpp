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

TEST_F(Psum_Tests,Create_Psum){
  int num_of_tuples = 2;
  Psum_Ptr Psum = Create_Psum(num_of_tuples);
  ASSERT_EQ(num_of_tuples,Psum->num_of_tuples);
}


TEST_F(Psum_Tests,Fill_Psum){
  Psum_Ptr Psum=Create_Psum(2);
  Fill_Psum(Histogram,Psum);
  ASSERT_EQ(100,Psum->Array[0].value);
  ASSERT_EQ(0,Psum->Array[0].sum);

  ASSERT_EQ(105,Psum->Array[1].value);
  ASSERT_EQ(200,Psum->Array[1].sum);
}


TEST_F(Psum_Tests,Get_Psum){
  Psum_Ptr Psum = Get_Psum(Histogram);
  ASSERT_EQ(100,Psum->Array[0].value);
  ASSERT_EQ(0,Psum->Array[0].sum);

  ASSERT_EQ(105,Psum->Array[1].value);
  ASSERT_EQ(200,Psum->Array[1].sum);

}