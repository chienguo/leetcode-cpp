#include "utils.h"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = ListNode(0, head);
    auto slow_p = &dummy;
    auto fast_p = &dummy;
    for (int i = 0; i < n; i++) {
      if (fast_p != nullptr) {
        fast_p = fast_p->next;
      } else {
        return nullptr;
      }
    }
    while (fast_p->next != nullptr) {
      fast_p = fast_p->next;
      slow_p = slow_p->next;
    }
    slow_p->next = slow_p->next->next;
    return dummy.next;
  }
};
}  // namespace

TEST(p0019, c1) {
  Solution s;
  // ASSERT_EQ(, );
}
