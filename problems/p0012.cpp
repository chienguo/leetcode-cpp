#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
  inline static const array<string, 10> I = {
      "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};  // 1~9
  inline static const array<string, 10> X = {
      "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};  // 10-90
  inline static const array<string, 10> C = {
      "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};  // 100-900
  inline static const array<string, 4> M = {"", "M", "MM", "MMM"};  // 1000-3000

 public:
  string intToRoman(int num) {
    string ans;
    ans.append(M[num / 1000]);
    ans.append(C[(num % 1000) / 100]);
    ans.append(X[(num % 100) / 10]);
    ans.append(I[num % 10]);
    return ans;
  }
};
}  // namespace

TEST(p0012, c1) {
  Solution s;
  ASSERT_EQ(s.intToRoman(3749), "MMMDCCXLIX");
}
