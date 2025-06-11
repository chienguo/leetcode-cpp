#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    array<array<int, 10>, 9> row;
    array<array<int, 10>, 9> col;
    array<array<int, 10>, 9> cell;
    for (size_t i = 0; i < 9; i++) {
      for (size_t j = 0; j < 9; j++) {
        auto num = (int)board[i][j] - (int)'1';
        if (row[i][num] >= 1 || col[j][num] >= 1 ||
            cell[(i / 3) * 3 + j / 3][num] >= 1) {
          return false;
        }
        row[i][num] = 1;
        col[j][num] = 1;
        cell[(i / 3) * 3 + j / 3][num] = 1;
      }
    }
    return true;
  }
};
} // namespace

TEST(p0036, c1) { Solution s; }
