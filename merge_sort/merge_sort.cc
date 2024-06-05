#include <iostream>
#include <vector>

void Merge(std::vector<int>& v,
           std::vector<int>& tv,
           int left_start,
           int right_start,
           int right_end) {
  int left_end = right_start - 1;
  int temp_pos = left_start;             /* 从当前子区间的左边开始 */
  int nums = right_end - left_start + 1; /* 当前区间的大小 */
  while (left_start <= left_end && right_start <= right_end) {
    if (v[left_start] <= v[right_start]) {
      tv[temp_pos++] = v[left_start++];
    } else {
      tv[temp_pos++] = v[right_start++];
    }
  }

  /* 将剩下的添加到尾部 */
  while (left_start <= left_end) {
    tv[temp_pos++] = v[left_start++];
  }
  while (right_start <= right_end) {
    tv[temp_pos++] = v[right_start++];
  }

  /* 将数据拷回原数组 */
  for (int i = 0; i < nums; i++, right_end--) {
    v[right_end] = tv[right_end];
  }
}

void MSort(std::vector<int>& v, std::vector<int>& tv, int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    MSort(v, tv, left, center);
    MSort(v, tv, center + 1, right);
    Merge(v, tv, left, center + 1, right);
  }
}

/* O(N log N) */
void MergeSort(std::vector<int>& v) {
  std::vector<int> tv(v.size());
  MSort(v, tv, 0, v.size() - 1);
}

int main(int argc, char** argv) {
  std::vector<int> v{22, 38, 46, 89, 12, 99, 50, 65, 48, 79, 36, 67};
  MergeSort(v);
  return EXIT_SUCCESS;
}