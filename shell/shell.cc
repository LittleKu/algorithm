#include <iostream>
#include <vector>

void shell_sort(std::vector<int>& v, int n) {
  int i = 0, j = 0, temp = 0;
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      temp = v[i]; /*< 保存当前位置的 */
      j = i;
      for (; j >= gap && temp < v[j - gap]; j -= gap) {
        v[j] = v[j - gap]; /* 与前 gap 位的元素对换*/
      }
      v[j] = temp; /*替换位置*/
    }
  }
}

int main(int argc, char** argv) {
  std::vector<int> v{22, 38, 46, 89, 12, 99, 50, 65, 48, 79, 36, 67};
  shell_sort(v, v.size());

  std::vector<int> v1{1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15, 8, 16};/* 最坏情况下 O(N^2) */
  shell_sort(v1, v1.size());
  return EXIT_SUCCESS;
}