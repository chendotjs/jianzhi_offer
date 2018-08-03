#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    if (k <= 0 || input.size() < k)
      return res;

    int start = 0;
    int end = input.size() - 1;
    int idx = partition(input, start, end);
    while (idx != k) {
      if (idx < k) {
        start = idx + 1;
      } else {
        end = idx - 1;
      }
      idx = partition(input, start, end);
    }
    res.assign(input.begin(), input.begin() + k);
    sort(res.begin(), res.end());
    return res;
  }

  int partition(vector<int> &input, int start, int end) {
    if (start >= end)
      return start;
    int i = start;
    int j = end + 1;
    do {
      do
        i++;
      while (i <= end && input[i] < input[start]);
      do
        j--;
      while (input[j] > input[start]);
      if (i < j) {
        swap(input[i], input[j]);
      }
    } while (i < j);
    swap(input[start], input[j]);
    return j;
  }
};
