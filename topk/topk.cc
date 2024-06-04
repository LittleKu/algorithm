#include <algorithm>
#include <iostream>

#include "partition/partition.hpp"

template <typename Predicate>
int random_select(std::vector<int>& v,
                  int low,
                  int high,
                  int k,
                  Predicate&& pred) {
  if (low == high) {
    return v[low];
  }

  int i = partition(v, low, high, std::forward<Predicate>(pred));
  int temp = i - low + 1;
  if (temp == k) {
    return v[i];
  } else if (temp > k) {
    return random_select(v, low, i - 1, k, std::forward<Predicate>(pred));
  } else {
    return random_select(v, i + 1, high, k - temp,
                         std::forward<Predicate>(pred));
  }
}

// cl.exe /EHsc /MDd /Od /DDEBUG /D_DEBUG /Zi /I. topk/topk.cc /link /DEBUG:FULL /SUBSYSTEM:CONSOLE /MACHINE:X86 /OUT:algorithm.exe",
int main(int argc, char** argv) {
  std::vector<int> v{12, 5, 534, 45, 468, 32, 65, 78, 25, 2, 60, 6, 1};
  const int k = 4;
  int result = random_select(
      v, 0, v.size() - 1, k,
      [](const int left, const int right) { return left > right; });
  std::cout << "topk:";
  for (int i = 0; i < k; i++)
    std::cout << v[i] << ",";
  std::cout << "\n";
  getchar();

  /* smallest k
  const int k = 5;
  int result = random_select(
      v, 0, v.size() - 1, k,
      [](const int left, const int right) { return left < right; });
  */
  return EXIT_SUCCESS;
}