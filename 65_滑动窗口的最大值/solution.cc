#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> res;
    deque<int> index;

    if (num.size() == 0 || size <= 0 || size > num.size())
      return res;

    for (int i = 0; i < size; i++) {
      while (index.empty() == false && num[i] >= num[index.back()])
        index.pop_back();
      index.push_back(i);
    }

    for (int i = size; i < num.size(); i++) {
      res.push_back(num[index.front()]);

      while (index.empty() == false && i - index.front() >= (int)size)
        index.pop_front();
      while (index.empty() == false && num[i] >= num[index.back()])
        index.pop_back();
      index.push_back(i);
    }
    res.push_back(num[index.front()]);
    return res;
  }
};
