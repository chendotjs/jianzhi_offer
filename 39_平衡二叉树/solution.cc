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
    unordered_map<TreeNode *, int> height_map;
    height_map[NULL] = 0;
    height(pRoot, height_map); // build map
    return IsBalanced(pRoot, height_map);
  }
  bool IsBalanced(TreeNode *pRoot, unordered_map<TreeNode *, int> &map) {
    if (pRoot == NULL)
      return true;
    int l = map[pRoot->left];
    int r = map[pRoot->right];
    if (l - r > 1 || r - l > 1)
      return false;
    return IsBalanced(pRoot->left, map) && IsBalanced(pRoot->right, map);
  }

  int height(TreeNode *pRoot, unordered_map<TreeNode *, int> &map) {
    if (pRoot == NULL)
      return 0;
    int l = height(pRoot->left, map);
    int r = height(pRoot->right, map);

    map[pRoot] = max(l, r) + 1;
    return map[pRoot];
  }
};
