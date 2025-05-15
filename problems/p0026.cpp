#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    auto n = nums.size();
    if (n <= 1)
      return (int)n;
    size_t l = 1, r = 1;
    while (r < n) {
      if (nums[r] != nums[l - 1]) {
        nums[l] = nums[r];
        l++;
      }
      r++;
    }
    return (int)l;
  }
};
} // namespace

TEST(p_, c1) {
  Solution s;
  vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  ASSERT_EQ(s.removeDuplicates(v), 5);
}
