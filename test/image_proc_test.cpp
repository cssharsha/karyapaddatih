#include "gtest/gtest.h"

#include "algos/image_proc.hpp"

using namespace ::testing;

class ImageProcTest : public Test {
  public:
    std::unique_ptr<algos::image_proc::ImageProc<float>> imagep;

    void SetUp() override {
      std::vector<std::vector<float>> image = {{1, 2, 1}, {1, 2, 2}, {1, 2, 0}};
      imagep = std::make_unique<algos::image_proc::ImageProc<float>>(image);
    }
};

TEST_F(ImageProcTest, BoxFilterTest) {
  imagep->applyFilter(algos::image_proc::BoxFilter<float>(3, 3));
  std::vector<std::vector<float>> image;
  imagep->GetImage(image);
  EXPECT_EQ(image, image);
}
