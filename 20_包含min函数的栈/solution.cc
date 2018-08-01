#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  stack<int> stk;
  stack<int> min_stk;
  int min_element;
  void push(int value) {
    if (stk.empty())
      min_element = INT_MAX;
    min_element = ::min(min_element, value);
    stk.push(value);
    min_stk.push(min_element);
  }
  void pop() {
    stk.pop();
    min_stk.pop();
  }
  int top() { return stk.top(); }
  int min() { return min_stk.top(); }
};
