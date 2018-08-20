#include <bits/stdc++.h>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
  bool isSymmetrical(TreeNode *pRoot) {
    if (pRoot == NULL)
      return true;
    return isSymmetrical(pRoot, pRoot);
  }

  bool isSymmetrical(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
      return true;
    if (root1 == NULL || root2 == NULL)
      return false;
    if (root1->val != root2->val)
      return false;
    return isSymmetrical(root1->left, root2->right) &&
           isSymmetrical(root1->right, root2->left);
  }
};
