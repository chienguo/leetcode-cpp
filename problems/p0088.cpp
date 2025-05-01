#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

namespace {
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    size_t i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0) {
      while (m >= 0 && nums1[m] > nums2[n]) {
        swap(nums1[i--], nums1[m--]);
      }
      swap(nums1[i--], nums2[n--]);
    }
  }
};
} // namespace

TEST(p0088, case1) {
  Solution s;
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  int m = 3;
  int n = 3;
  s.merge(nums1, m, nums2, n);
  vector<int> expected{1, 2, 2, 3, 5, 6};
  ASSERT_EQ(nums1, expected);
}

// 添加更多测试用例...