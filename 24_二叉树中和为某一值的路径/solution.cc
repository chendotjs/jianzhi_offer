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
  vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    vector<vector<int>> res;
    vector<int> path;
    if (root == NULL)
      return res;

    dfs(root, expectNumber, path, res);
    return res;
  }

  void dfs(TreeNode *root, int expectNumber, vector<int> &path,
           vector<vector<int>> &res) {
    if (root->left == NULL && root->right == NULL) {
      if (expectNumber == root->val) {
        path.push_back(root->val);
        res.push_back(path);
        path.pop_back();
      }
      return;
    }
    if (root != NULL) {
      path.push_back(root->val);
      if (root->left)
        dfs(root->left, expectNumber - root->val, path, res);
      if (root->right)
        dfs(root->right, expectNumber - root->val, path, res);
      path.pop_back();
    }
  }
};
