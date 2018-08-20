#include <bits/stdc++.h>
using namespace std;

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
  TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    assert(pNode != NULL);
    if (pNode->right) {
      TreeLinkNode *root = pNode->right;
      while (root->left != NULL)
        root = root->left;
      return root;
    } else if (pNode->next != NULL) {
      if (pNode->next->left == pNode) { // 是左孩子
        return pNode->next;
      } else { // 是右孩子
        TreeLinkNode *root = pNode;
        TreeLinkNode *parent = root->next;
        while (parent != NULL && root == parent->right) {
          root = parent;
          parent = root->next;
        }
        return parent;
      }
    }
    return NULL;
  }
};
