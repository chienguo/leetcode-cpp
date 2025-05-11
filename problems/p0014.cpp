#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    sort(strs.begin(), strs.end());
    auto first = strs.front();
    auto last = strs.back();
    size_t cl = 0;
    for (size_t i = 0; i < min(first.size(), last.size()); i++) {
      if (first[i] != last[i]) {
        break;
      }
      cl += 1;
    }
    return first.substr(0, cl);
  }
};
} // namespace

TEST(p0014, c1) {
  Solution s;
  auto strs = vector<string>{"flower", "flow", "flight"};
  ASSERT_EQ(s.longestCommonPrefix(strs), "fl");
}
