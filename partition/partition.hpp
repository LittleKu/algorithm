#ifndef PARTITION_HPP_
#define PARTITION_HPP_

#include <vector>

template <typename Predicate>
int partition(std::vector<int>& nums, int low, int high, Predicate&& pred) {
  int key = nums[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (pred(nums[j], key)) {
      i++;
      std::swap(nums[i], nums[j]);
    }
  }
  std::swap(nums[i + 1], nums[high]);
  return i + 1;
}

#endif