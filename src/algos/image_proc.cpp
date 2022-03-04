#include <iostream>
#include <vector>

#include "algos/image_proc.hpp"

namespace algos {
  namespace image_proc {

    template <typename T>
      bool BoxFilter<T>::operator() (ImageProc<T>* img) {

        int M = img->rows(), N = img->cols();
        ImageProc<T> sum_image = *img;

        for (int i = 0;i < M;i++) {
          for (int j = 0;j < N;j++) {
            int sum_i_1_j = i - 1 < 0? 0: sum_image->at(i - 1, j);
            int sum_i_j_1 = j - 1 < 0? 0: sum_image->at(i, j - 1);
            int sum_i_1_j_1 = i - 1 < 0 || j - 1 < 0? 0: sum_image->at(i - 1, j - 1);

            sum_image->at(i, j) = sum_i_1_j + sum_i_j_1 - sum_i_1_j_1 + img->at(i, j);
          }
        }

        std::cout << "Sum image: \n";
        std::cout << sum_image;

            // sum(i, j) = sum(i + filter_size / 2, j + filter_size / 2) -
            //                sum(i - filter_size / 2, j) - sum(i, j - filter_size / 2) +
            //                sum(i - filter_size / 2, j - filter_size / 2)
        return true;
      }
  }
}
