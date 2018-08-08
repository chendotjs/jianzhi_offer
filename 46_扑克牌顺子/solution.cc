#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool IsContinuous(vector<int> numbers) {
    if (numbers.size() == 0)
      return false;
      
    int king_num = 0;
    int absent_num = 0;
    sort(numbers.begin(), numbers.end());

    for (int i : numbers) {
      if (i == 0)
        king_num++;
      else
        break;
    }

    for (int i = king_num + 1; i < numbers.size(); i++) {
      if (numbers[i] == numbers[i - 1])
        return false;
      absent_num += numbers[i] - numbers[i - 1] - 1;
    }
    return king_num >= absent_num;
  }
};
