#include <bits/stdc++.h>
using namespace std;

bool cmp(const int lhs, const int rhs) {
  string l = to_string(lhs);
  string r = to_string(rhs);
  return l + r < r + l;
}

class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    string res;
    if (numbers.size() == 0)
      return res;
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto i : numbers)
      res += to_string(i);
    return res;
  }
};
