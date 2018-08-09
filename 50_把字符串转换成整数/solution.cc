#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int StrToInt(string str) {
    if (str.size() == 0)
      return 0;
    int num_start = 0;
    bool negative = false;

    if (str[0] == '-' || str[0] == '+') {
      negative = str[0] == '-' ? true : false;
      num_start = 1;
    }

    int res = 0;
    for (int i = num_start; i < str.size(); i++) {
      if (!isdigit(str[i]))
        return false;
      res = res * 10 + str[i] - '0';
    }

    res = negative ? -res : res;
    return res;
  }
};
