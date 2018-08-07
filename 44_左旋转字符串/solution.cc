#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string LeftRotateString(string str, int n) {
    if (n < 0 || str.size() == 0)
      return str;
    n %= str.size();
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
  }
};
