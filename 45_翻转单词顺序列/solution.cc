#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string ReverseSentence(string str) {
    if (str.size() <= 1)
      return str;
    reverse(str.begin(), str.end());
    auto left = str.begin(), right = str.begin();
    while (left != str.end()) {
      if (*left == ' ') {
        left++;
        right++;
      } else if (right == str.end() || *right == ' ') {
        reverse(left, right);
        left = right;
      } else if (*right != ' ') {
        right++;
      }
    }
    return str;
  }
};

int main(int argc, char const *argv[]) {
  { cout << Solution().ReverseSentence("abc def") << endl; }
  return 0;
}
