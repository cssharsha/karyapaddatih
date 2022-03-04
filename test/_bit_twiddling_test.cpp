#include "gtest/gtest.h"

#include "algos/bit_twidling.hpp"

using namespace ::testing;

template <typename T>
class BitTwiddlingTest : public Test {
  public:
    typename ::bits::benchmark::BitTwidling<T> bitt;
};

using testing::Types;
typedef Types<int, float, double> BitTwiddlingTypes;

TYPED_TEST_SUITE(BitTwiddlingTest, BitTwiddlingTypes);

TYPED_TEST(BitTwiddlingTest, ComputeSignBranching) {
  EXPECT_EQ(this->bitt.computeSignBranching(400.0), 1);
  EXPECT_EQ(this->bitt.computeSignBranching(-400.0), 0);
}

TYPED_TEST(BitTwiddlingTest, ComputeSignNoBranching) {
  EXPECT_EQ(this->bitt.computeSignNoBranching(400.0), 1);
  EXPECT_EQ(this->bitt.computeSignNoBranching(-400.0), 0);
}

TYPED_TEST(BitTwiddlingTest, ComputeSignThree) {
  EXPECT_EQ(this->bitt.computeSignThree(400.0), 1);
  EXPECT_EQ(this->bitt.computeSignThree(-400.0), -1);
  EXPECT_EQ(this->bitt.computeSignThree(0), 0);
}

TYPED_TEST(BitTwiddlingTest, OppositeSign) {
  EXPECT_TRUE(this->bitt.checkOppositeSigns(300.0, -300.0));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(400.0, -300.0));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300.0, -300.0));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300.0, 300.0));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(-300.0, 400.0));
  EXPECT_TRUE(this->bitt.checkOppositeSigns(0, 0));
}

TYPED_TEST(BitTwiddlingTest, Absolute) {
  EXPECT_EQ(this->bitt.computeAbs(300), 300);
  EXPECT_EQ(this->bitt.computeAbs(-300), 300);
  EXPECT_EQ(this->bitt.computeAbs(0), 0);
}
