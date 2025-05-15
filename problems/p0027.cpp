#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    size_t left = 0;
    for (size_t right = 0; right < nums.size(); right++) {
      if (nums[right] != val) {
        nums[left] = nums[right];
        left++;
      }
    }
    return (int)left;
  }
};
} // namespace

TEST(p_, c1) {
  Solution s;
  vector<int> v{0, 1, 2, 2, 3, 0, 4, 2};
  ASSERT_EQ(s.removeElement(v, 2), 5);
}
