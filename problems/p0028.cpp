#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  int strStr(string haystack, string needle) {
    return (int)haystack.find(needle);
  }
};
} // namespace

TEST(p0028, c1) {
  Solution s;
  ASSERT_EQ(s.strStr("sadbutsad", "sad"), 0);
}
