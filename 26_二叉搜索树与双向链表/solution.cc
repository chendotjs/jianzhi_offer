#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lastNode;
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (!pRootOfTree)
      return pRootOfTree;
    lastNode = NULL;
    TreeNode *head = pRootOfTree;
    while (head->left != NULL) {
      head = head->left;
    }
    MergeList(pRootOfTree);
    return head;
  }

  void MergeList(TreeNode *root) {
    if (!root)
      return;
    MergeList(root->left);
    root->left = lastNode;
    if (lastNode)
      lastNode->right = root;
    lastNode = root;
    MergeList(root->right);
  }
};
