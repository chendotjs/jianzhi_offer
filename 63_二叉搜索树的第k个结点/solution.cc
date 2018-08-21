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
  TreeNode *KthNode(TreeNode *pRoot, int k) {
    TreeNode *res = NULL;
    KthNode(pRoot, k, res);
    return res;
  }

  void KthNode(TreeNode *pRoot, int &k, TreeNode *&res) {
    if (pRoot) {
      KthNode(pRoot->left, k, res);
      k--;
      if (k == 0) {
        res = pRoot;
        return;
      }
      KthNode(pRoot->right, k, res);
    }
  }
};
