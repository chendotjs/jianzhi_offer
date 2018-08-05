#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int FirstNotRepeatingChar(string str) {
    if (str.size() == 0)
      return -1;
    vector<int> hash(256, 0);
    int size = str.size();
    int res = -1;
    for (int i = 0; i < size; i++)
      hash[str[i]]++;
    for (int i = 0; i < size; i++) {
      if (hash[str[i]] == 1) {
        res = i;
        break;
      }
    }
    return res;
  }
};
