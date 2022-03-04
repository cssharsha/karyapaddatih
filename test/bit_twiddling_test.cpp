#include "gtest/gtest.h"

#include "algos/bit_twidling.hpp"

using namespace ::testing;

class BitTwiddlingTest : public Test {
  public:
    ::bits::benchmark::BitTwidling bitt;
};

TEST_F(BitTwiddlingTest, ComputeSignBranching) {
  EXPECT_EQ(this->bitt.computeSignBranching(400), 1);
  EXPECT_EQ(this->bitt.computeSignBranching(-400), 0);
}

TEST_F(BitTwiddlingTest, ComputeSignNoBranching) {
  EXPECT_EQ(this->bitt.computeSignNoBranching(400), 1);
  EXPECT_EQ(this->bitt.computeSignNoBranching(-400), 0);
}

TEST_F(BitTwiddlingTest, ComputeSignThree) {
  EXPECT_EQ(this->bitt.computeSignThree(400), 1);
  EXPECT_EQ(this->bitt.computeSignThree(-400), -1);
  EXPECT_EQ(this->bitt.computeSignThree(0), 0);
}

TEST_F(BitTwiddlingTest, OppositeSign) {
  EXPECT_TRUE(this->bitt.checkOppositeSigns(300, -300));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(400, -300));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300, -300));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300, 300));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300, 400));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(0, 0));
}

TEST_F(BitTwiddlingTest, Absolute) {
  EXPECT_EQ(this->bitt.computeAbs(300), 300);
  EXPECT_EQ(this->bitt.computeAbs(-300), 300);
  EXPECT_EQ(this->bitt.computeAbs(0), 0);
}
