#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
    int res = 0;
    for (auto i : data)
      res ^= i;
    int n1 = 0, n2 = 0;
    int idx = findFistBit1(res);
    int filter = 0x01 << idx;
    for (auto i : data) {
      if (i & filter) {
        n1 ^= i;
      } else {
        n2 ^= i;
      }
    }
    *num1 = min(n1, n2);
    *num2 = max(n1, n2);
  }

  int findFistBit1(int num) {
    int base = 0x01;
    int idx = 0;
    while (base != 0) {
      if (base & num)
        return idx;
      base = base << 1;
      idx++;
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {2, 4, 3, 6, 3, 2, 5, 5};
    int n1, n2;
    Solution().FindNumsAppearOnce(vec, &n1, &n2);
  }
  return 0;
}
