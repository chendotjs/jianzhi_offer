#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> Permutation(string str) {
    sort(str.begin(), str.end());
    vector<string> res;
    if (str.size() == 0)
      return res;
    vector<bool> visited(str.size(), false);
    vector<char> path;
    dfs(str, path, visited, res);
    return res;
  }

  void dfs(string &str, vector<char> &path, vector<bool> &visited,
           vector<string> &res) {
    if (str.size() == path.size()) {
      string s;
      for (auto c : path)
        s += c;
      res.push_back(s);
      return;
    }
    for (int i = 0; i < str.size(); i++) {
      if (visited[i])
        continue;
      if (i >= 1 && str[i] == str[i - 1] && visited[i - 1] == false) // remove dup
        continue; // 去掉重复
      visited[i] = true;
      path.push_back(str[i]);
      dfs(str, path, visited, res);
      path.pop_back();
      visited[i] = false;
    }
  }
};

int main(int argc, char const *argv[]) {
  {
    Solution().Permutation("abc");
    Solution().Permutation("aab");
    Solution().Permutation("aaa");
  }
  return 0;
}
