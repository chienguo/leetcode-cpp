struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool areListsEqual(ListNode *l1, ListNode *l2) {
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val != l2->val) {
      return false;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  // Both must be nullptr at the end
  return (l1 == nullptr && l2 == nullptr);
}

// const int values[] = {__VA_ARGS__};
#define LINKLIST(...)                         \
  ([] {                                       \
    const vector<int> values = {__VA_ARGS__}; \
    ListNode *head = nullptr;                 \
    ListNode **current = &head;               \
    for (int v : values) {                    \
      *current = new ListNode(v);             \
      current = &((*current)->next);          \
    }                                         \
    return head;                              \
  })()
