#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

namespace {
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    auto n = nums.size();
    vector<vector<int>> ans;
    for (size_t i = 0; i < n - 2; i++) {
      auto x = nums[i];
      if (i > 0 && x == nums[i - 1]) continue;
      if (x + nums[i + 1] + nums[i + 2] > 0) break;
      if (x + nums[n - 2] + nums[n - 1] < 0) continue;
      size_t j = i + 1, k = n - 1;
      while (j < k) {
        auto sum = x + nums[j] + nums[k];
        if (sum > 0)
          k--;
        else if (sum < 0)
          j++;
        else {
          ans.emplace_back(initializer_list<int>{x, nums[j], nums[k]});
          j++;
          while (j < k && nums[j] == nums[j - 1]) j++;
          k--;
          while (k > j && nums[k] == nums[k + 1]) k--;
        }
      }
    }

    return ans;
  }
};
}  // namespace

TEST(p0015, c1) {
  Solution s;
  // ASSERT_EQ(, );
}
