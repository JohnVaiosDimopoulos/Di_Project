#include <gtest/gtest.h>
#include "../../Histogram/Histogram.c"
#include "../../Initializer/Relations_Initializer.h"
class Histogram_Tests : public ::testing::Test {
 public:
  RelationPtr Relation,Relation_big;
  const char* filename ="./Test_Files/Test_Table_1";
  const char* filename_big = "./Test_Files/Test_Table_Big";

 protected:
 protected:
  virtual void TearDown() {
  Delete_Relation(Relation);
  Delete_Relation(Relation_big);
  }

  virtual void SetUp() {
   Initialize_Relation(&Relation,filename);
   Initialize_Relation(&Relation_big,filename_big);
  }
};


TEST_F(Histogram_Tests, Create_And_Init_Histogram){
  Histogram_Ptr Histogram =Create_And_Init_Histogram();
  for(int i =0;i<HISTOGRAM_SIZE;i++){
    ASSERT_EQ(0,Histogram->Array[i]);
  }
}

TEST_F(Histogram_Tests,Fill_Histogram_last_byte){
  Histogram_Ptr Histogram = Create_And_Init_Histogram();
  Fill_Histogram(Relation,Histogram,1);

  ASSERT_EQ(0,Histogram->Array[0]);
  for(int i = 1;i<7;i++){
    ASSERT_EQ(1,Histogram->Array[i]);
  }

  for (int j = 8; j <HISTOGRAM_SIZE ; ++j) {
    ASSERT_EQ(0,Histogram->Array[j]);
  }
}

TEST_F(Histogram_Tests,Fill_Histogram_middle_byte_test){
  Histogram_Ptr Histogram  = Create_And_Init_Histogram();
  Fill_Histogram(Relation,Histogram,3);
  ASSERT_EQ(7,Histogram->Array[0]);
  for (int i = 1; i <HISTOGRAM_SIZE ; ++i) {
    ASSERT_EQ(0,Histogram->Array[i]);
  }
}

TEST_F(Histogram_Tests,Fill_Histogram_big_relation){
  Histogram_Ptr Histogram = Create_And_Init_Histogram();
  Fill_Histogram(Relation_big,Histogram,8);
  ASSERT_EQ(200,Histogram->Array[23]);
  ASSERT_EQ(800,Histogram->Array[96]);
}

TEST_F(Histogram_Tests,Get_Histogram_last_byte){
  Histogram_Ptr Histogram = Get_Histogram(Relation,1);
  ASSERT_EQ(0,Histogram->Array[0]);
  for(int i = 1;i<7;i++){
    ASSERT_EQ(1,Histogram->Array[i]);
  }

  for (int j = 8; j <HISTOGRAM_SIZE ; ++j) {
    ASSERT_EQ(0,Histogram->Array[j]);
  }
}

TEST_F(Histogram_Tests,Get_Histogram_middle_byte){
  Histogram_Ptr Histogram = Get_Histogram(Relation,4);
  ASSERT_EQ(7,Histogram->Array[0]);
  for (int i = 1; i <HISTOGRAM_SIZE ; ++i) {
    ASSERT_EQ(0,Histogram->Array[i]);
  }
}

TEST_F(Histogram_Tests,Get_Histogram_big_file){
  Histogram_Ptr Histogram = Get_Histogram(Relation_big,8);
  ASSERT_EQ(200,Histogram->Array[23]);
  ASSERT_EQ(800,Histogram->Array[96]);
}