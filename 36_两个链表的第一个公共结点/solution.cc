#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL || pHead2 == NULL)
      return NULL;

    stack<ListNode *> stk1, stk2;
    ListNode *res = NULL;

    for (auto head = pHead1; head != NULL; head = head->next)
      stk1.push(head);
    for (auto head = pHead2; head != NULL; head = head->next)
      stk2.push(head);

    while (!stk1.empty() && !stk2.empty()) {
      if (stk1.top() == stk2.top())
        res = stk1.top();
      else
        break;
      stk1.pop();
      stk2.pop();
    }
    return res;
  }
};
