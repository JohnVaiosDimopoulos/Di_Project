#include <gtest/gtest.h>
#include "../../Histogram/Histogram.c"

class Histogram_Tests : public ::testing::Test {
 public:
  RelationPtr Relation;

 protected:
 protected:
  virtual void TearDown() {
  }

  virtual void SetUp() {
  }

};

TEST_F(Histogram_Tests, Create_Histogram) {
  Histogram_Ptr Histogram = Create_Histogram(Relation);

////////////////////////////////////////
  ASSERT_EQ(Histogram->num_of_tuples, num_of_tuples);
  ASSERT_EQ(Histogram->num_of_elements,num_of_elements);
////////////////////////////////////////
}

TEST_F(Histogram_Tests,Create_Histogram_Wrong) {
  Histogram_Ptr Histogram = Create_Histogram(NULL);
  ASSERT_EQ(nullptr,Table);
}
