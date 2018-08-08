#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int LastRemaining_Solution(int n, int m) {
    if (n < 1 || m < 1)
      return -1;

    list<int> children(n);
    int i = 0;
    for (auto it = children.begin(); it != children.end(); it++)
      *it = i++;

    auto start = children.begin();
    while (children.size() > 1) {
      for (int i = 0; i < m - 1; i++) {
        start++;
        if (start == children.end()) // circle linked list
          start = children.begin();
      }
      start = children.erase(start);
      if (start == children.end()) // circle linked list
        start = children.begin();
    }
    return *children.begin();
  }
};

int main(int argc, char const *argv[]) {
  {
    cout << Solution().LastRemaining_Solution(2, 1) << endl; // 1
    cout << Solution().LastRemaining_Solution(2, 2) << endl; // 0
    cout << Solution().LastRemaining_Solution(2, 3) << endl; // 1
    cout << Solution().LastRemaining_Solution(5, 3) << endl; // 3
  }
  return 0;
}
