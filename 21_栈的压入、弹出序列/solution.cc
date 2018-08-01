#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> stk;
    int i = 0;
    int j = 0;
    while (j < popV.size()) {
      if (stk.empty() || stk.top() != popV[j]) {
        if (i >= pushV.size())
          break;
        stk.push(pushV[i++]);
      } else {
        stk.pop();
        j++;
      }
    }
    return stk.empty();
  }
};
