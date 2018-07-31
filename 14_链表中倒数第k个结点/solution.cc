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
  ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
    if (pListHead == NULL || k == 0)
      return NULL;
    ListNode *slow = pListHead, *fast = pListHead;
    for (int i = 0; i < k - 1; i++) {
      if (fast == NULL || fast->next == NULL) // in case invalid input
        return NULL;
      fast = fast->next;
    }
    while (fast->next != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
