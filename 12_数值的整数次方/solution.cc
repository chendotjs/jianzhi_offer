#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-4)

class Solution {
public:
  double Power(double base, int exponent) {
    if (base < EPS && base > -EPS)
      return 0;
    if (exponent == 0)
      return 1;

    if (exponent < 0) {
      base = 1.0 / base;
      exponent = -exponent;
    }

    double res = 1;
    while (exponent) {
      if (exponent & 0x01) {
        res *= base;
      }
      base *= base;
      exponent = exponent >> 1;
    }
    return res;
  }
};
