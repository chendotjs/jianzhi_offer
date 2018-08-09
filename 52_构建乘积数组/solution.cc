#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> multiply(const vector<int> &A) {
    int size = A.size();
    vector<int> res(size);
    if (size == 0)
      return res;
    vector<int> FW(size, A[0]);
    vector<int> BW(size, A[size - 1]);

    for (int i = 1; i < size; i++)
      FW[i] = FW[i - 1] * A[i];

    for (int i = size - 2; i >= 0; i--)
      BW[i] = BW[i + 1] * A[i];

    for (int i = 0; i < size; i++) {
      if (i == 0)
        res[i] = BW[i + 1];
      else if (i == size - 1)
        res[i] = FW[i - 1];
      else
        res[i] = FW[i - 1] * BW[i + 1];
    }
    return res;
  }
};
