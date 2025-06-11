#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows > s.length()) {
      return s;
    }
    string ans;
    auto t = 2 * numRows - 2;
    for (size_t i = 0; i < numRows; i++) {
      for (size_t j = 0; j < s.length() - i; j += t) {
        ans.push_back(s[i + j]);
        if (0 < i && i < numRows - 1 && j + t - i < s.length()) {
          ans.push_back(s[j + t - i]);
        }
      }
    }
    return ans;
  }
};
}  // namespace

TEST(p0006, c1) {
  Solution s;
  ASSERT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
  ASSERT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}
