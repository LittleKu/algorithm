#include <iostream>
#include <vector>

int parent_index(int child) {
  return (child - 1) / 2;
}

int left_index(int parent) {
  return parent * 2 + 1;
}

int right_index(int parent) {
  return parent * 2 + 2;
}

void max_heapify(std::vector<int>& arr, int n, int index) {
  int left = left_index(index);
  int right = right_index(index);
  int largest = index;

  /* 从左右子节点中找出最大值 */
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != index) {
    std::swap(arr[index], arr[largest]);
    max_heapify(arr, n, largest);
  }
}

void build_max_heap(std::vector<int>& arr) {
  /* 从最后一个非叶子节点开始 */
  for (int i = (arr.size() - 1 - 1) / 2; i >= 0; i--) {
    max_heapify(arr, arr.size(), i);
  }
}

std::vector<int> heap_sort(std::vector<int>& arr, int k) {
  build_max_heap(arr);
  std::vector<int> result;
  for (int i = arr.size() - 1; i >= 0 && k-- > 0; i--) {
    std::swap(arr[0], arr[i]); /* 将堆顶元素与最后一个元素交换 */
    result.push_back(arr[i]);  /* 取出最大值 */
    max_heapify(arr, i, 0);
  }
  return result;
}
int main(int argc, char** argv) {
  std::vector<int> array = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  std::cout << "heap sort:";
  for (const int& i : heap_sort(array, array.size() / 2)) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  return EXIT_SUCCESS;
}