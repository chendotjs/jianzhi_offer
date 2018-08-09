#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int Add(int num1, int num2) {
    int carry = 0, sum = 0;

    while (num2 != 0) {
      sum = num1 ^ num2;
      carry = (num1 & num2) << 1;
      num1 = sum;
      num2 = carry;
    }
    return num1;
  }
};

int main(int argc, char const *argv[]) {
  cout << Solution().Add(1, 3) << endl;
  cout << Solution().Add(5, 8) << endl;
  cout << Solution().Add(15, 8) << endl;
  return 0;
}
