#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool IsBalanced_Solution(TreeNode *pRoot) {
    int depth = 0;
    return IsBalanced(pRoot, depth);
  }
  bool IsBalanced(TreeNode *pRoot, int &height) {
    if (pRoot == NULL) {
      height = 0;
      return true;
    }

    int l, r; // 左右子树的高度，由父节点存储
    if (IsBalanced(pRoot->left, l) && IsBalanced(pRoot->right, r)) {
      if (l - r > 1 || r - l > 1)
        return false;
      height = max(l, r) + 1;
      return true;
    }
    return false;
  }
};
