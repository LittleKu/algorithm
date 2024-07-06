#include <iostream>
#include <vector>

int trap(const std::vector<int>& height) {
  int left = 0, right = height.size() - 1;
  int left_max = 0, right_max = 0;
  int ans = 0;
  while (left < right) {
    if (height[left] > height[right]) {
      if (height[right] > right_max) {
        right_max = height[right];
      } else {
        ans += right_max - height[right];
      }
      right--;
    } else {
      if (height[left] > left_max) {
        left_max = height[left];
      } else {
        ans += left_max - height[left];
      }
      left++;
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << trap(height) << std::endl;
  return EXIT_SUCCESS;
}