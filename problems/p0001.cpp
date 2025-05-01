#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  vector<int> twoSum(std::vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = map.find(target - nums[i]);
      if (it != map.end()) {
        return {it->second, i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};
} // namespace

TEST(p0001, case1) {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  vector<int> expected = {0, 1};
  ASSERT_EQ(s.twoSum(nums, 9), expected);
}

TEST(p0001, case2) {
  Solution s;
  vector<int> nums = {3, 2, 4};
  vector<int> expected = {1, 2};
  ASSERT_EQ(s.twoSum(nums, 6), expected);
}