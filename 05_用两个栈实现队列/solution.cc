#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void push(int node) { stack1.push(node); }

  int pop() {
    int res;
    if (stack2.empty()) {
      while (stack1.empty() == false) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    res = stack2.top();
    stack2.pop();
    return res;
  }

private:
  stack<int> stack1; // 存储push的
  stack<int> stack2;
};
