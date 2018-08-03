#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    int res;
    int middle = numbers.size() / 2;
    int idx;
    int start = 0;
    int end = numbers.size() - 1;
    idx = partition(numbers, start, end);
    while (idx != middle) {
      if (idx < middle) {
        start = idx + 1;
        idx = partition(numbers, start, end);
      } else {
        end = idx - 1;
        idx = partition(numbers, start, end);
      }
    }

    res = numbers[middle];
    if (validInput(numbers, res) == false)
      res = 0;
    return res;
  }

  int partition(vector<int> &numbers, int start, int end) {
    if (start >= end)
      return start;

    int i = start;
    int j = end + 1;
    while (i < j) {
      do
        i++;
      while (i <= end && numbers[i] < numbers[start]);
      do
        j--;
      while (numbers[j] > numbers[start]);
      if (i < j) {
        swap(numbers[i], numbers[j]);
      }
    }
    swap(numbers[j], numbers[start]);
    return j;
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
