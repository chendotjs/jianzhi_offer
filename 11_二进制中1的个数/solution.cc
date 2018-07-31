#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int NumberOf1(int n) {
    int cnt = 0;
    int flag = 0x01;
    while (flag) {
      if (n & flag)
        cnt++;
      flag = flag << 1;
    }
    return cnt;
  }
};


int main(int argc, char const *argv[]) {
  {
    cout << Solution().NumberOf1(-1) << endl;
  }
  return 0;
}
