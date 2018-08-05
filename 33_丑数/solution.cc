#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int GetUglyNumber_Solution(int index) {
    if (index == 0)
      return 0;
    vector<int> res(index);
    res[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for (int i = 1; i < index; i++) {
      res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
      if (res[t2] * 2 == res[i])
        t2++;
      if (res[t3] * 3 == res[i])
        t3++;
      if (res[t5] * 5 == res[i])
        t5++;
    }
    return res[index - 1];
  }
};
