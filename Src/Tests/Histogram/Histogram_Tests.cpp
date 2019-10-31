#include <gtest/gtest.h>
#include "../../Histogram/Histogram.c"
#include "../../Initializer/Relations_Initializer.h"
class Histogram_Tests : public ::testing::Test {
 public:
  RelationPtr Relation;
  const char* filename ="./Test_Files/Test_Table_1";

 protected:
 protected:
  virtual void TearDown() {
  Delete_Relation(Relation);
  }

  virtual void SetUp() {
   Initialize_Relation(&Relation,filename);
  }
};


TEST_F(Histogram_Tests,Count_Histogram_Rows_Last_byte){
  int expected = 7;
  int result = Count_Histogram_Rows(Relation,1);
  ASSERT_EQ(expected, result);
}


TEST_F(Histogram_Tests,Count_Histogram_Rows_Random_byte){
  int expected=1;
  int result = Count_Histogram_Rows(Relation,3);
  ASSERT_EQ(expected, result);
}

