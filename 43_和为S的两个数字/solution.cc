#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> res(2, -1);
    int multi = INT_MAX;
    int left = 0, right = array.size() - 1;
    while (left < right) {
      int cur_sum = array[left] + array[right];
      if (cur_sum == sum) {
        if (array[left] * array[right] < multi) {
          multi = array[left] * array[right];
          res[0] = min(array[left], array[right]);
          res[1] = max(array[left], array[right]);
        }
        left++;
      } else if (cur_sum < sum)
        left++;
      else
        right--;
    }
    if (res[0] == -1) // not found
      res.erase(res.begin(), res.end());
    return res;
  }
};
