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
  vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> res;
    if (root == NULL)
      return res;

    queue<TreeNode *> Q;
    Q.push(root);
    while (Q.empty() == false) {
      auto node = Q.front();
      Q.pop();
      res.push_back(node->val);

      if (node->left)
        Q.push(node->left);
      if (node->right)
        Q.push(node->right);
    }
    return res;
  }
};
