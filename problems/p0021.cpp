#include "utils.h"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto dummy = ListNode();
    auto ptr = &dummy;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        ptr->next = list1;
        list1 = list1->next;
        ptr = ptr->next;
      } else {
        ptr->next = list2;
        list2 = list2->next;
        ptr = ptr->next;
      }
    }
    if (list1 != nullptr)
      ptr->next = list1;
    else
      ptr->next = list2;

    return dummy.next;
  }
};
}  // namespace

TEST(p_, c1) {
  Solution s;
  // ASSERT_EQ(, );
}
