#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    priority_queue<int, vector<int>> Q; //最大堆
    vector<int> res;
    if (k <= 0)
      return res;
    for (auto element : input) {
      if (Q.size() < k) {
        Q.push(element);
        continue;
      }
      if (element < Q.top()) {
        Q.pop();
        Q.push(element);
      }
    }
    while (Q.size() != 0) {
      res.push_back(Q.top());
      Q.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {4, 5, 1, 6, 2, 7, 3, 8};
    auto r = Solution().GetLeastNumbers_Solution(vec, 4);
    r = r;
  }
  return 0;
}
