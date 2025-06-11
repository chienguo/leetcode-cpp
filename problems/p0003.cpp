#include <algorithm>
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

namespace {
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    auto res = 0;
    auto left = 0;
    auto window = unordered_set<char>();
    for (size_t i = 0; i < s.length(); i++) {
      while (window.find(s.at(i)) != window.end()) {
        window.erase(s[left]);
        left++;
      }
      window.insert(s.at(i));
      res = max(res, (int)i - left + 1);
    }
    return res;
  }
};
}  // namespace

TEST(p0003, c1) {
  Solution s;
  ASSERT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}
