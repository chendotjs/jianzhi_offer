#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    if (pHead == NULL)
      return NULL;

    ListNode *slow = pHead, *fast = pHead;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
        goto cycle;
    }
    return NULL;
  cycle:;
    slow = pHead;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
