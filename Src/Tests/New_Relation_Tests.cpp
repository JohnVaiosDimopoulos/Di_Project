#include <gtest/gtest.h>
#include "../New_Relation.c"
#include "../Histogram/Histogram.c"
#include "../Prefix_sum/Prefix_Sum.c"


#include "../Initializer/Relations_Initializer.h"


class New_Relation_Tests : public ::testing::Test {
public:

    RelationPtr Relation,Relation_big;
    const char* filename ="./Test_Files/Test_Table_1";
    Histogram_Ptr  Histogram;
    Psum_Ptr Psum;


protected:
protected:
    virtual void TearDown() {
        Delete_Relation(Relation);
    }

    virtual void SetUp() {
        Initialize_Relation(&Relation,filename);
        Histogram= Get_Histogram(Relation,1);
        Psum = Get_Psum(Histogram);
    }
};

TEST_F(New_Relation_Tests, Find_in_Histogram_Wrong) {
    uint8_t byte = 10;
    Hist_Tuple_Ptr hist_tuple = Find_in_Histogram(Histogram, byte);

    ASSERT_EQ(nullptr, hist_tuple);
}

TEST_F(New_Relation_Tests, Find_in_Psum_Wrong) {
    uint8_t byte = 10;
    Psum_Tuple_Ptr psum_tuple = Find_in_Psum(Psum, byte);

    ASSERT_EQ(nullptr, psum_tuple);
}

TEST_F(New_Relation_Tests, Is_Last_Tupple_true) {
    Psum_Tuple_Ptr psum_tuple = &Psum->Array[7];
    int res = Is_Last_Tupple(Psum, psum_tuple);

    ASSERT_EQ(res, 1);
}

TEST_F(New_Relation_Tests, Is_Last_Tupple_false) {
    Psum_Tuple_Ptr psum_tuple = &Psum->Array[3];
    int res = Is_Last_Tupple(Psum, psum_tuple);

    ASSERT_EQ(res, 0);
}



TEST_F(New_Relation_Tests,  Copy_Relation) {

}

TEST_F(New_Relation_Tests, Copy_Relation_Wrong) {

}