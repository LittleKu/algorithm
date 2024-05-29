#include <algorithm>
#include <iostream>
#include <vector>

int partition(std::vector<int>& v, int low, int high) {
  if (high == low) {
    return low;
  }
  int i = low;
  int j = high;
  int key = v[low];
  while (true) {
    while (v[i] <= key) {
      i++;
      if (v[i] >= key) {
        break;
      }
    }
    while (v[j] >= key) {
      j--;
      if (v[j] <= key) {
        break;
      }
    }
    if (i >= j) {
      break;
    }
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
  }
  v[low] = v[j];
  v[j] = key;
  return j;
}

void quick_sort(std::vector<int>& v, int low, int high) {
  if (high <= low) {
    return;
  }

  int j = partition(v, low, high);

  quick_sort(v, low, j - 1);
  quick_sort(v, j + 1, high);
}

int random_select(std::vector<int>& v, int low, int high, int k) {
  if (low == high) {
    return v[low];
  }

  int i = partition(v, low, high);
  int temp = i - low + 1;
  if (temp == k) {
    return v[i];
  } else if (temp > k) {
    return random_select(v, low, i - 1, k);
  } else {
    return random_select(v, i + 1, high, k - temp);
  }
}

int main(int argc, char** argv) {
  std::vector<int> v{12, 5, 534, 45, 468, 32, 65, 78, 25, 2, 60, 6, 1};
  // quick_sort(v, 0, v.size() - 1);
  int result = random_select(v, 0, v.size() - 1, 4);
  return EXIT_SUCCESS;
}