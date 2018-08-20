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
    queue<TreeNode *> Q;
    vector<int> level_vec;
    Q.push(pRoot);
    int cur_level = 1;  // 当前层次节点个数
    int next_level = 0; // 下一层次节点个数
    int level = 0;      // 第几层，偶数层次从左向右，奇数反之

    while (Q.size() != 0) {
      auto node = Q.front();
      level_vec.push_back(node->val);
      Q.pop();

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
        if (level % 2 == 1)
          reverse(level_vec.begin(), level_vec.end());
        level++;
        res.push_back(level_vec);
        level_vec.erase(level_vec.begin(), level_vec.end());
      }
    }
    return res;
  }
};
