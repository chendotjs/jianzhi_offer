#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() <= 0)
      return false;
    return VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
  }

  bool VerifySquenceOfBST(vector<int> &sequence, int start, int end) {
    if (start == end)
      return true;
    int i;
    for (i = start; i <= end - 1; i++) {
      if (sequence[i] > sequence[end])
        break;
    }

    for (int j = i; j <= end - 1; j++) {
      if (sequence[j] < sequence[end])
        return false;
    }

    bool left = true, right = true;
    if (i != 0) // left child exists
      left = VerifySquenceOfBST(sequence, start, i - 1);
    if (i != end) // right child exists
      right = VerifySquenceOfBST(sequence, i, end - 1);
    return left && right;
  }
};
