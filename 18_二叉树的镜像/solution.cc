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
};*/
class Solution {
public:
  void Mirror(TreeNode *pRoot) {
    if (pRoot) {
      TreeNode *old_left_child = pRoot->left;
      TreeNode *old_right_child = pRoot->right;
      pRoot->right = old_left_child;
      pRoot->left = old_right_child;
      Mirror(old_left_child);
      Mirror(old_right_child);
    }
  }
};
