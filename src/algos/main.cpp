#include "merge_sort.hpp"
#include <iostream>
#include <vector>

template <typename T>
void print_vector_helper(const std::vector<T>& v, const std::string& header) {
  std::cout << header << ":" << std::endl;
  for (const auto& elem:v) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}


int count = 1;

int main(int argc, char  **argv) {
  std::vector<int> input = {2, 6,  3, 7, 1, -2};
  print_vector_helper<int>(input, "Before sort");
  mergeSort<int>(input);
  print_vector_helper<int>(input, "After sort");
  return 0;
}
