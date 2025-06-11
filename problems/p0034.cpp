#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    size_t start = lower(nums, target);
    if (start == nums.size() || nums[start] != target) {
      return {-1, -1};
    }
    size_t end = lower(nums, target + 1) - 1;
    return {(int)start, (int)end};
  }

  size_t lower(vector<int> &nums, int target) {
    size_t left = 0, right = 0;
    while (left < right) {
      auto mid = (left + right - right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
} // namespace

TEST(p0034, c1) { Solution s; }
