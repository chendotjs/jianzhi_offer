#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    int res = numbers[0];
    int balance = 1;
    for (int i = 0; i < numbers.size(); i++) {
      if (balance == 0) {
        res = numbers[i];
        balance = 1;
      } else if (numbers[i] == numbers[i - 1])
        balance++;
      else
        balance--;
    }
    if (validInput(numbers, res) == false)
      res = 0;
    return res;
  }

  bool validInput(vector<int> &numbers, int result) {
    int cnt = 0;
    for (auto i : numbers) {
      if (i == result)
        cnt++;
    }
    return 2 * cnt > numbers.size();
  }
};
