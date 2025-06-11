#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {
class Solution {
 public:
  int romanToInt(string s) {
    auto map =
        unordered_map<char, int>{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};
    auto ans = 0;
    for (size_t i = 0; i < s.length() - 1; i++) {
      auto cur = map[s[i]];
      auto next = map[s[i + 1]];
      if (cur < next) {
        ans -= cur;
      } else {
        ans += cur;
      }
    }
    return ans + map[s.back()];
  }
};
}  // namespace

TEST(p0013, c1) {
  Solution s;
  ASSERT_EQ(s.romanToInt("LVIII"), 58);
}
