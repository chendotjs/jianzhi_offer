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
  vector<vector<int>> Print(TreeNode *pRoot) {
    vector<vector<int>> res;
    if (pRoot == NULL)
      return res;

    int cur_level = 1;
    int next_level = 0;
    queue<TreeNode *> Q;
    vector<int> level;
    Q.push(pRoot);

    while (Q.empty() == false) {
      auto node = Q.front();
      Q.pop();
      level.push_back(node->val);

      if (node->left) {
        Q.push(node->left);
        next_level++;
      }
      if (node->right) {
        Q.push(node->right);
        next_level++;
      }
      cur_level--;
      if (cur_level == 0) {
        cur_level = next_level;
        next_level = 0;
        res.push_back(level);
        level.erase(level.begin(), level.end());
      }
    }
    return res;
  }
};
