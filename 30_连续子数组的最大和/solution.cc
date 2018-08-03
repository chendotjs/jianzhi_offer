#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    int size = array.size();
    vector<int> dp(size, array[0]);
    int res = array[0];

    for (int i = 1; i < size; i++) {
      dp[i] = std::max(dp[i - 1] + array[i], array[i]);
      res = std::max(dp[i], res);
    }
    return res;
  }
};
