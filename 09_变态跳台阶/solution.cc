#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
      return 0x01 << (number - 1);
    }
};
