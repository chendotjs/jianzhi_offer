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
  char *Serialize(TreeNode *root) {
    string res;
    Serialize(root, res);

    char *ret = new char[res.length() + 1];
    for (int i = 0; i < res.length(); i++) {
      ret[i] = res[i];
    }
    ret[res.length()] = '\0';
    return ret;
  }

  void Serialize(TreeNode *root, string &res) {
    if (root == NULL) {
      res += "#,";
      return;
    }
    res.append(to_string(root->val) + ",");
    Serialize(root->left, res);
    Serialize(root->right, res);
  }
  TreeNode *Deserialize(char *str) { return Deserialize(str, 0); }

  TreeNode *Deserialize(char *&str, int no_use) {
    if (str == NULL)
      return NULL;
    if (*str == '#' || *str == '\0') {
      str += 2;
      return NULL;
    }
    int num = 0;
    while (*str != ',') {
      num = num * 10 + *str - '0';
      str++;
    }
    str++;
    TreeNode *root = new TreeNode(num);
    root->left = Deserialize(str, 0);
    root->right = Deserialize(str, 0);
    return root;
  }
};
