#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    if (sum <= 0)
      return res;
    int left = 1, right = 2;
    int cur_sum = 3;
    while (left <= sum / 2) {
      if (cur_sum == sum) {
        vector<int> tmp;
        for (int i = left; i <= right; i++)
          tmp.push_back(i);
        res.push_back(tmp);
        // left move forward
        cur_sum -= left;
        left++;
      } else if (cur_sum < sum) {
        right++;
        cur_sum += right;
      } else {
        cur_sum -= left;
        left++;
      }
    }
    return res;
  }
};
