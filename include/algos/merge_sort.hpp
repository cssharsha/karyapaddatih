#include <vector>

template <typename T>
void merge(std::vector<T>& input, int left, int mid, int right) {
  int left_size = mid - left + 1;
  int right_size = right - mid;

  std::vector<T> left_array, right_array;

  for (int i = 0;i < left_size;i++) {
    left_array.push_back(input[left + i]);
  }

  for (int i = 0;i < right_size;i++) {
    right_array.push_back(input[mid + 1 + i]);
  }

  int left_index = 0, right_index = 0, merged_index = left;
  while (left_index < left_size && right_index < right_size)  {
    if (left_array[left_index] <= right_array[right_index]) {
      input[merged_index] = left_array[left_index];
      left_index++;
    } else {
      input[merged_index] = right_array[right_index];
      right_index++;
    }
    merged_index++;
  }

  while (left_index < left_size) {
    input[merged_index] = left_array[left_index];
    left_index++;
    merged_index++;
  }

  while (right_index < right_size) {
    input[merged_index] = right_array[right_index];
    right_index++;
    merged_index++;
  }
}

template <typename T>
void mergeSort(std::vector<T>& input, int left, int right) {
  if (left >= right)
    return;

  int mid = (left + right) / 2;

  mergeSort<T>(input, left, mid);
  mergeSort<T>(input, mid + 1, right);
  merge<T>(input, left, mid, right);
}

template <typename T>
std::vector<T> mergeSort(std::vector<T>& input) {
  mergeSort<T>(input, 0, input.size());
  return input;
}
