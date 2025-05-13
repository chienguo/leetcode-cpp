struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define LINKLIST(...)                                                          \
  ([] {                                                                        \
    const int values[] = {__VA_ARGS__};                                        \
    ListNode *head = nullptr;                                                  \
    ListNode **current = &head;                                                \
    for (int v : values) {                                                     \
      *current = new ListNode(v);                                              \
      current = &((*current)->next);                                           \
    }                                                                          \
    return head;                                                               \
  })()