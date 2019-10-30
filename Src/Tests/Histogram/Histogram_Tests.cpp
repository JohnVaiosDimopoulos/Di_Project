#include <gtest/gtest.h>
#include "../../../Initializer/Histogram/Histogram.c"

class Histogram_Tests : public ::testing::Test {
 public:
  Data_Table_Ptr Table;

 protected:
 protected:
  virtual void TearDown() {
  }

  virtual void SetUp() {
  }

};

TEST_F(Histogram_Tests, Create_Histogram) {
  Histogram_Ptr Histogram = Create_Histogram(Table);

////////////////////////////////////////
  ASSERT_EQ(Histogram->num_of_rows, num_of_rows);
  ASSERT_EQ(Histogram->num_of_elements,num_of_elements);
////////////////////////////////////////
}

TEST_F(Data_Table_Tests,Create_Data_Table_Wrong) {
  Histogram_Ptr Histogram = Create_Histogram(NULL);
  ASSERT_EQ(nullptr,Table);
}
