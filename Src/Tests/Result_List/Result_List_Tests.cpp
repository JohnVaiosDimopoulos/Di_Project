#include <gtest/gtest.h>
#include "../../Results_List/Results_List.c"

class Result_List_Tests : public ::testing::Test {

};


TEST_F(Result_List_Tests,Create_and_Init){
  List_Ptr List = Create_and_Initialize_List();
  ASSERT_EQ(List->start,List->last);
  ASSERT_EQ(List->num_of_nodes,0);
  Delete_List(List);
}

TEST_F(Result_List_Tests,Insert_Record_empty){
  List_Ptr List = Create_and_Initialize_List();
  Insert_Record(List,2,2);
  ASSERT_EQ(List->start->Array[0][0],2);
  ASSERT_EQ(List->start->Array[0][1],2);
  Delete_List(List);
}

TEST_F(Result_List_Tests,Insert_Record_force_to_make_new_node){
  List_Ptr List = Create_and_Initialize_List();
  for(int i =0;i<65535;i++){
    Insert_Record(List,i,i);
  }
  // this should be inserted in a second node;
  Insert_Record(List,65535,65535);
  ASSERT_NE(List->start,List->last);
  ASSERT_EQ(List->num_of_nodes,1);
  for(int i =0;i<6535;i++){
    ASSERT_EQ(List->start->Array[i][0],i);
    ASSERT_EQ(List->start->Array[i][1],i);
  }
  ASSERT_EQ(List->last->Array[0][0],65535);
  ASSERT_EQ(List->last->Array[0][1],65535);
  Delete_List(List);
}

TEST_F(Result_List_Tests,Is_Empty_true){
  List_Ptr List = Create_and_Initialize_List();
  ASSERT_EQ(1,Is_Empty(List));
}

TEST_F(Result_List_Tests,Is_Empty_false){
  List_Ptr List = Create_and_Initialize_List();
  Insert_Record(List,1,1);
  ASSERT_EQ(0,Is_Empty(List));
}