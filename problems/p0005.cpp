#include <bits/stdc++.h>
#include <cstddef>
#include <gtest/gtest.h>
#include <tuple>

using namespace std;

namespace {
class Solution {
public:
  string longestPalindrome(string s) {
    size_t start_idx = 0, max = 1;
    for (size_t i = 0; i < s.length(); i++) {
      auto [start1, len1] = check(s, i, i);
      auto [start2, len2] = check(s, i, i + 1);
      if (len2 > len1) {
        if (len2 > max) {
          start_idx = start2;
          max = len2;
        }
      } else {
        if (len1 > max) {
          start_idx = start1;
          max = len1;
        }
      }
    }
    string res;
    for (size_t i = 0; i < s.length(); i++) {
      if (i >= start_idx && i < start_idx + max) {
        res.push_back(s[i]);
      }
    }
    return res;
  }

  tuple<size_t, size_t> check(const string &s, size_t lt, size_t rt) {
    while (rt < s.length() && s[lt] == s[rt]) {
      if (lt == 0) {
        return make_tuple(0, rt + 1);
      }
      rt += 1;
      lt -= 1;
    }
    return make_tuple(lt + 1, rt - lt - 1);
  }
};
} // namespace

TEST(p0005, c1) {
  Solution s;
  ASSERT_EQ(s.longestPalindrome("babad"), "bab");
  ASSERT_EQ(s.longestPalindrome("cbbd"), "bb");
}