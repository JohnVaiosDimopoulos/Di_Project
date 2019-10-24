#include <gtest/gtest.h>
#include "../../Util/String_Managing.c"

class String_Managing_Tests : public ::testing::Test {
 public:
  const char* str = "Test String";
 protected:
  virtual void TearDown() {

  }
  virtual void SetUp() {

  }
};

TEST_F(String_Managing_Tests,Allocate_and_Copy){
  char* new_String=Allocate_and_Copy(str);
  ASSERT_STREQ(new_String,"Test String");
}