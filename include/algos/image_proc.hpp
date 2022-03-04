#include <cmath>
#include <functional>
#include <vector>

namespace algos {
  namespace image_proc {

    template <typename T>
      class ImageProc;

    template <typename T>
      struct BoxFilter {
        BoxFilter(const int filter_height, const int filter_width) :
          filter_height_(filter_height),
          filter_width_(filter_width) {
          }

        bool operator() (ImageProc<T>* img) {
          int M = img->rows(), N = img->cols();
          std::unique_ptr<ImageProc<T>> sum_image = std::make_unique<ImageProc<T>>(*img);

          for (int i = 0;i < M;i++) {
            for (int j = 0;j < N;j++) {
              int sum_i_1_j = i - 1 < 0? 0: sum_image->at(i - 1, j);
              int sum_i_j_1 = j - 1 < 0? 0: sum_image->at(i, j - 1);
              int sum_i_1_j_1 = i - 1 < 0 || j - 1 < 0? 0: sum_image->at(i - 1, j - 1);

              sum_image->at(i, j) = sum_i_1_j + sum_i_j_1 - sum_i_1_j_1 + img->at(i, j);
            }
          }

          std::cout << "Sum image: \n" << *sum_image;

          std::unique_ptr<ImageProc<T>> filter_sum_image =
            std::make_unique<ImageProc<T>>(M, N);

          for (int i = 0;i < M; i++) {
            for (int j = 0;j < N; j++) {
              int i_beg, j_beg;
              int i_end, j_end;

              int height = std::ceil((float)filter_height_ / 2.0f);
              int width = std::ceil((float)filter_width_ / 2.0f);

              i_beg = i - height;
              j_beg = j - width;

              i_end = (i + height >= M)? M - 1: i + height - 1;
              j_end = (j + width >= N)? N - 1: j + width - 1;


              int filter_sum_i_end_j_end = sum_image->at(i_end, j_end);
              int filter_sum_i_beg_j_end = (i_beg < 0)? 0: sum_image->at(i_beg, j_end);
              int filter_sum_i_end_j_beg = (j_beg < 0)? 0: sum_image->at(i_end, j_beg);
              int filter_sum_i_beg_j_beg = (i_beg < 0 || j_beg < 0)? 0: sum_image->at(i_beg, j_beg);

              std::cout << i << ", " << j << ": " <<
                filter_sum_i_end_j_end << ", " <<
                filter_sum_i_beg_j_end << ", " <<
                filter_sum_i_end_j_beg << ", " <<
                filter_sum_i_beg_j_beg << "\n";

              filter_sum_image->at(i, j) =
                filter_sum_i_end_j_end -
                filter_sum_i_beg_j_end -
                filter_sum_i_end_j_beg +
                filter_sum_i_beg_j_beg;
            }
          }

          std::cout << "Filter sum:\n" << *filter_sum_image;

          return true;
        }

        private:
        int filter_height_, filter_width_;
      };

    template <typename T>
      class ImageProc {
        public:
          ImageProc(std::vector<std::vector<T>>& image) :
            rows_(image.size()),
            cols_(image.at(0).size()),
            image_(image) {
            }

          ImageProc(const ImageProc<T>& img) :
            rows_(img.rows()),
            cols_(img.cols()),
            image_(img.GetImage()) {
            }

          ImageProc() :
            rows_(0),
            cols_(0) {
            }

          ImageProc(int rows, int cols) :
            rows_(rows), cols_(cols) {
              image_.resize(rows_, std::vector<T>(cols_, 0));
            }

          std::vector<std::vector<T>> GetImage() const {
            return image_;
          }

          void GetImage(std::vector<std::vector<T>>& image_out) {
            image_out = image_;
          }

          T& at(int row, int col) {
            return image_.at(row).at(col);
          }

          int rows() const { return rows_; }

          int cols() const { return cols_; }

          void SetImage(std::vector<std::vector<T>>&& image_in) {
            rows_ = image_in.size();
            cols_ = image_in.at(0).size();
            image_ = image_in;
            /* std::move(image_in, image_); */
          }

          bool applyFilter(
              std::function<bool(ImageProc<T>* img)>&& filter) {
            return filter(this);
          }

          friend std::ostream& operator<<(std::ostream& os, const ImageProc<T>& img) {
            for (const auto& row : img.image_) {
              for (const auto& elem : row) {
                os << elem << " ";
              }
              os << "\n";
            }
            return os;
          }

        private:
          std::vector<std::vector<T>> image_;
          int rows_, cols_;
      };

    template class ImageProc<float>;
    template class ImageProc<double>;
    template class ImageProc<int>;

  }
}
