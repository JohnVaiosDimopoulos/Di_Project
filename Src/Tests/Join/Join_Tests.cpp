#include <gtest/gtest.h>
#include "../../Join/Join.c"
#include "../../Initializer/Relations_Initializer.h"


//define these for quicker access to the list
typedef struct List_node* Node_Ptr;
struct List_node{
  uint64_t Array[LIST_SIZE][2];
  int counter;
  Node_Ptr next;
};
struct Result_List{
  long num_of_nodes;
  Node_Ptr start;
  Node_Ptr last;
};
//

class Join_Test : public ::testing::Test {
 public:
 List_Ptr Result_List;
 RelationPtr Relation_A,Relation_B;
 protected:
  virtual void TearDown() {
    Delete_List(Result_List);
  }
  virtual void SetUp() {
    Result_List=Create_and_Initialize_List();
  }

};

TEST_F(Join_Test,Join_Success){
  Initialize_Relation(&Relation_A,"./Test_Files/Test_Table_1");
  Initialize_Relation(&Relation_B,"./Test_Files/Test_Table_2");
  Join_Relations(Relation_A,Relation_B,Result_List);

  ASSERT_EQ(Result_List->start->Array[0][0],1);
  ASSERT_EQ(Result_List->start->Array[0][1],3);

  ASSERT_EQ(Result_List->start->Array[1][0],2);
  ASSERT_EQ(Result_List->start->Array[1][1],4);

  ASSERT_EQ(Result_List->start->Array[2][0],3);
  ASSERT_EQ(Result_List->start->Array[2][1],8);
  Delete_Relation(Relation_A);
  Delete_Relation(Relation_B);
}

TEST_F(Join_Test,Join_Test_Fail){
  Initialize_Relation(&Relation_A,"./Test_Files/Test_Table_1_Join_Fail");
  Initialize_Relation(&Relation_B,"./Test_Files/Test_Table_2_Join_Fail");
  Join_Relations(Relation_A,Relation_B,Result_List);

  ASSERT_EQ(Result_List->start->counter,0);
}