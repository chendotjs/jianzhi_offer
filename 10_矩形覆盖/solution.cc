#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rectCover(int number) {
    if (number == 0)
      return 0;
    int a = 1, b = 2, c = 3;
    if (number <= 2)
      return number == 1 ? a : b;
    number -= 2;
    while (number--) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};
