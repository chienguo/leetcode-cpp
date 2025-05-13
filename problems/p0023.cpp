#include "utils.h"
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <queue>
#include <vector>

using namespace std;

namespace {
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto dummy = ListNode();
    auto ptr = &dummy;

    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    auto queue =
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)>(cmp);

    for (auto list : lists) {
      if (list != nullptr) {
        queue.push(list);
      }
    }

    while (!queue.empty()) {
      if (queue.top()->next != nullptr)
        queue.push(queue.top()->next);
      ptr->next = queue.top();
      ptr = ptr->next;
      queue.pop();
    }

    return dummy.next;
  }
};
} // namespace

TEST(p0023, c1) {
  // [[1,4,5],[1,3,4],[2,6]]
  Solution s;
  auto l1 = LINKLIST(1, 4, 5);
  auto l2 = LINKLIST(1, 3, 4);
  auto l3 = LINKLIST(2, 6);
  auto v = vector<ListNode *>{l1, l2, l3};
  auto expected = LINKLIST(1, 1, 2, 3, 4, 4, 5, 6);
  ASSERT_EQ(s.mergeKLists(v), expected);
}
