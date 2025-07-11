#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "utils.h"

using namespace std;

namespace {
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto dummy = ListNode();
    auto cur = &dummy;
    auto carry = 0;
    while (l1 || l2 || carry != 0) {
      auto sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
    }
    return dummy.next;
  }
};
}  // namespace

TEST(p0002, c1) {}
