#include <algorithm>
#include <iostream>
#include <vector>

void insert_sort(std::vector<int>& v) {
  const int size = static_cast<int>(v.size());
  if (size <= 1) {
    return;
  }
  for (int i = 1; i < size; i++) {
    int j = i - 1;
    if (v[i] > v[j]) {
      int temp = v[i];
      while (j >= 0 && v[j] > temp) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = temp;
    }
  }
}

template <typename Predicate>
void insert_sort_pred(std::vector<int>& v, Predicate pred) {
  const int size = static_cast<int>(v.size());
  if (size <= 1) {
    return;
  }

  for (int i = 1; i < size; i++) {
    int j = i - 1;
    if (pred(v[i], v[j])) {
      int temp = v[i];
      while (j >= 0 && pred(temp, v[j])) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = temp;
    }
  }
}

int main(int argc, char** argv[]) {
  std::vector<int> v{57, 68, 59, 52, 27, 72, 28, 96, 33, 24};
  //   insert_sort(v);
  insert_sort_pred(v, std::less<int>());
  return EXIT_SUCCESS;
}