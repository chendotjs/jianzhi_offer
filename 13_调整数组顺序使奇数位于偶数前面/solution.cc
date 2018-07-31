#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void reOrderArray(vector<int> &array) {
    vector<int> odd, even;
    for (auto i : array) {
      if (i & 0x01)
        odd.push_back(i);
      else
        even.push_back(i);
    }
    int cnt = 0;
    for (auto i : odd)
      array[cnt++] = i;
    for (auto i : even)
      array[cnt++] = i;
  }
};
