#include <bits/stdc++.h>
using namespace std;

class Helper {
public:
  static int cnt;
  static int sum;
  Helper() {
    sum += ++cnt;
  }
};

int Helper::cnt = 0;
int Helper::sum = 0;


class Solution {
public:
    int Sum_Solution(int n) {
      Helper::cnt = 0;
      Helper::sum = 0;
      Helper arr[n];
      return Helper::sum;
    }
};
