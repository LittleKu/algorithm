#include <iostream>

#include "partition/partition.hpp"

template <typename Predicate>
void quick_sort(std::vector<int>& v, int low, int high, Predicate&& pred) {
  if (low >= high)
    return;

  int i = partition(v, low, high, std::forward<Predicate>(pred));

  quick_sort(v, low, i - 1, std::forward<Predicate>(pred));
  quick_sort(v, i + 1, high, std::forward<Predicate>(pred));
}

// cl.exe /EHsc /MDd /Od /DDEBUG /D_DEBUG /Zi /I. quick_sort/quick_sort.cc /link /DEBUG:FULL /MACHINE:X86 /SUYSYSTEM:CONSOLE /OUT:algorithm.exe",
int main(int argc, char** argv[]) {
  std::vector<int> v{12, 5, 534, 45, 468, 32, 65, 78, 25, 2, 60, 6, 1};

  // ascending order
  quick_sort(v, 0, v.size() - 1,
             [](const int left, const int right) { return left < right; });
  // descending order
  quick_sort(v, 0, v.size() - 1,
             [](const int left, const int right) { return left > right; });
  return EXIT_SUCCESS;
}