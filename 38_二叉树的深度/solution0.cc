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
  int TreeDepth(TreeNode *pRoot) {
    int max_depth = 0;
    dfs(pRoot, 0, max_depth);
    return max_depth;
  }
  void dfs(TreeNode *pRoot, int depth, int &max_depth) {
    if (pRoot == NULL) {
      max_depth = max(max_depth, depth);
      return;
    }
    dfs(pRoot->left, depth + 1, max_depth);
    dfs(pRoot->right, depth + 1, max_depth);
  }
};
