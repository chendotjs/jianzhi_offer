#include <bits/stdc++.h>
using namespace std;
/*
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
                        val(x), next(NULL) {
        }
};*/
class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL)
      return pHead2;
    if (pHead2 == NULL)
      return pHead1;

    ListNode *pHead;
    if (pHead1->val <= pHead2->val) {
      pHead = pHead1;
      pHead->next = Merge(pHead1->next, pHead2);
    } else {
      pHead = pHead2;
      pHead->next = Merge(pHead1, pHead2->next);
    }
    return pHead;
  }
};
