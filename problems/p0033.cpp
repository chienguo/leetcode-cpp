#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    size_t i = findMin(nums);
    if (target > nums[nums.size() - 1]) {
      return lowerBound(nums, 0, i, target);
    } else {
      return lowerBound(nums, i, nums.size(), target);
    }
  }

 private:
  size_t findMin(vector<int> &nums) {
    size_t left = 0, right = nums.size() - 1;
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (nums[mid] < nums[nums.size() - 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }

  int lowerBound(vector<int> &nums, size_t left, size_t right, int target) {
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (nums[right] == target) {
      return (int)right;
    }
    return -1;
  }
};
}  // namespace

TEST(p0033, c1) {
  Solution s;
  vector<int> v{4, 5, 6, 7, 0, 1, 2};
  ASSERT_EQ(s.search(v, 0), 4);
}
