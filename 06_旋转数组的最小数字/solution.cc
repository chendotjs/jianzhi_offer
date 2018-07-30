#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    int left = 0, right = rotateArray.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (rotateArray[left] < rotateArray[right])
        break;

      if (rotateArray[mid] == rotateArray[left] &&
          rotateArray[left] == rotateArray[right])
        return minInOrder(rotateArray);
      if (rotateArray[mid] >= rotateArray[left])
        left = mid + 1;
      else if (rotateArray[mid] <= rotateArray[left])
        right = mid;
    }
    return rotateArray[left];
  }

  int minInOrder(vector<int> &rotateArray) {
    for (int i = 1; i < rotateArray.size(); i++)
      if (rotateArray[i] < rotateArray[i - 1])
        return rotateArray[i];
    return -1;
  }
};
