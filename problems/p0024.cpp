#include "utils.h"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    auto dummy = ListNode();
    dummy.next = head;
    auto cur = &dummy;
    while (cur->next != nullptr) {
      if (cur->next->next != nullptr) {
        auto first = cur->next;
        auto second = cur->next->next;
        first->next = second->next;
        second->next = first;
        cur->next = second;
        cur = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};
}  // namespace

TEST(p0024, c1) {
  Solution s;
  auto l = LINKLIST(1, 2, 3, 4);
  auto r = LINKLIST(2, 1, 4, 3);
  ASSERT_EQ(areListsEqual(s.swapPairs(l), r), true);
}
