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

TEST_F(Histogram_Tests,Count_Histogram_Rows_Big_File){
  int expected=2;
  int result = Count_Histogram_Rows(Relation_big,1);
  ASSERT_EQ(expected, result);
}

TEST_F(Histogram_Tests,Create_Histogram){
  int histogram_rows_num=3;
  Histogram_Ptr Histogram=Create_Histogram(histogram_rows_num);
  ASSERT_EQ(Histogram->num_of_tuples,histogram_rows_num);
}


TEST_F(Histogram_Tests,Fill_Histogram_Last_byte){
  int histogram_rows_num=7;
  Histogram_Ptr Histogram = Create_Histogram(histogram_rows_num);
  Fill_Histogram(Relation,Histogram,1);
  for(int i =0;i<Histogram->num_of_tuples;i++){
    ASSERT_EQ(1,Histogram->Array[i].quantity);
    ASSERT_EQ(i+1,Histogram->Array[i].value);
  }
}


TEST_F(Histogram_Tests,Fill_Histogram_Random_byte){
  int histogram_rows_num=1;
  Histogram_Ptr Histogram = Create_Histogram(histogram_rows_num);
  Fill_Histogram(Relation,Histogram,3);
  for(int i =0;i<Histogram->num_of_tuples;i++){
    ASSERT_EQ(7,Histogram->Array[i].quantity);
    ASSERT_EQ(0,Histogram->Array[i].value);
  }
}


TEST_F(Histogram_Tests,Fill_Histogram_Big_File){
  int histogram_rows_num=2;
  Histogram_Ptr Histogram = Create_Histogram(histogram_rows_num);
  Fill_Histogram(Relation_big,Histogram,1);
  ASSERT_EQ(100,Histogram->Array[0].value);
  ASSERT_EQ(200,Histogram->Array[0].quantity);

  ASSERT_EQ(105,Histogram->Array[1].value);
  ASSERT_EQ(800,Histogram->Array[1].quantity);
}


TEST_F(Histogram_Tests,Get_Histogram_Last_byte){
  Histogram_Ptr Histogram = Get_Histogram(Relation,1);
  for(int i =0;i<Histogram->num_of_tuples;i++){
    ASSERT_EQ(1,Histogram->Array[i].quantity);
    ASSERT_EQ(i+1,Histogram->Array[i].value);
  }

}


TEST_F(Histogram_Tests,Get_Histogram_First_byte){
  Histogram_Ptr Histogram = Get_Histogram(Relation,8);
  for(int i =0;i<Histogram->num_of_tuples;i++){
    ASSERT_EQ(7,Histogram->Array[i].quantity);
    ASSERT_EQ(0,Histogram->Array[i].value);
  }

}


TEST_F(Histogram_Tests,Get_Histogram_Big_FILE){
  Histogram_Ptr Histogram = Get_Histogram(Relation_big,1);
  ASSERT_EQ(100,Histogram->Array[0].value);
  ASSERT_EQ(200,Histogram->Array[0].quantity);

  ASSERT_EQ(105,Histogram->Array[1].value);
  ASSERT_EQ(800,Histogram->Array[1].quantity);
}