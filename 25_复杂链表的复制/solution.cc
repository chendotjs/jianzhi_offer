#include <bits/stdc++.h>
using namespace std;

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
  RandomListNode *Clone(RandomListNode *pHead) {
    if (pHead == NULL)
      return NULL;
    unordered_map<RandomListNode *, RandomListNode *> map;
    map[NULL] = NULL;
    dfs(pHead, map);
    return map[pHead];
  }

  void dfs(RandomListNode *head,
           unordered_map<RandomListNode *, RandomListNode *> &map) {
    if (map.find(head) != map.end())
      return;
    map[head] = new RandomListNode(head->label);
    dfs(head->next, map);
    dfs(head->random, map);
    map[head]->next = map[head->next];
    map[head]->random = map[head->random];
  }
};
