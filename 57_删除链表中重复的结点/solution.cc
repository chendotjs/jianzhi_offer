#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplication(ListNode *pHead) {
    if (pHead == NULL)
      return pHead;
    ListNode new_head(pHead->val - 1);
    new_head.next = pHead;
    ListNode *slow = &new_head, *fast = (&new_head)->next;
    while (fast != NULL) {
      while (fast->next != NULL && fast->next->val == fast->val) {
        fast = fast->next;
      }
      if (slow->next == fast) {
        slow = slow->next;
        fast = fast->next;
      } else {
        slow->next = fast->next;
        fast = fast->next;
      }
    }
    return new_head.next;
  }
};
