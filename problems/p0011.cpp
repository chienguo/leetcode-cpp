#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  int maxArea(vector<int> &height) {
    size_t ans = 0;
    size_t left = 0, right = height.size() - 1;
    while (left < right) {
      auto area = (right - left) * min(height[left], height[right]);
      ans = max(ans, area);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return (int)ans;
  }
};
} // namespace

TEST(p0011, c1) {
  Solution s;
  auto height = vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7};
  ASSERT_EQ(s.maxArea(height), 49);
}
