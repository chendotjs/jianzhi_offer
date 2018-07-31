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
  ListNode *ReverseList(ListNode *pHead) {
    if (pHead == NULL || pHead->next == NULL)
      return pHead;

    ListNode *p = pHead, *q = p->next, *r = q->next;
    while (q != NULL) {
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    pHead->next = NULL;
    return p;
  }
};
