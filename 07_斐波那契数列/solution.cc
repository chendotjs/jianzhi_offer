#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int Fibonacci(int n) {
    int a = 0, b = 1, c = 1;
    if (n <= 1)
      return n == 0 ? a : b;

    n--;
    while (n--) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};
