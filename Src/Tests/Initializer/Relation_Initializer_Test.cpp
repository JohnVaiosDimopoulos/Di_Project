#include <gtest/gtest.h>
#include "../../Initializer/Relations_Initializer.c"

class Relation_Initializer_Test : public ::testing::Test {
 public:
  RelationPtr Relation;
  const char* Empty="./Test_Files/empty";
};


TEST_F(Relation_Initializer_Test,Initialize_Input_empty){
  ASSERT_EXIT(Initialize_Relation(&Relation,"./Test_Files/empty"),::testing::ExitedWithCode(255),"");
}
