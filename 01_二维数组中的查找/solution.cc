#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool Find(int target, vector<vector<int>> array) {
    if (array.size() == 0 || array[0].size() == 0)
      return false;
    int i = 0, j = array[0].size() - 1;
    while (i <= array.size() - 1 && j >= 0) {
      if (target == array[i][j])
        return true;
      else if (target > array[i][j])
        i++;
      else
        j--;
    }
    return false;
  }
};
