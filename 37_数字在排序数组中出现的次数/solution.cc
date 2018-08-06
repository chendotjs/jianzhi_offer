#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int GetNumberOfK(vector<int> data, int k) {
    int size = data.size();
    int res = 0;
    if (size == 0)
      return res;
    int start = GetFirstK(data, k, 0, size - 1);
    int end = GetLastK(data, k, 0, size - 1);
    if (start != -1 && end != -1)
      res = end - start + 1;
    return res;
  }

  int GetFirstK(vector<int> &data, int k, int start, int end) {
    if (start > end)
      return -1;
    int mid = start + (end - start) / 2;
    if (data[mid] < k) {
      start = mid + 1;
    } else if (data[mid] > k) {
      end = mid - 1;
    } else if (data[mid] == k) {
      if ((mid >= 1 && data[mid - 1] != k) || mid == 0)
        return mid;
      else {
        end = mid - 1;
      }
    }
    return GetFirstK(data, k, start, end);
  }

  int GetLastK(vector<int> &data, int k, int start, int end) {
    if (start > end)
      return -1;
    int mid = start + (end - start) / 2;
    if (data[mid] < k) {
      start = mid + 1;
    } else if (data[mid] > k) {
      end = mid - 1;
    } else if (data[mid] == k) {
      if ((mid + 1 <= data.size() - 1 && data[mid + 1] != k) ||
          mid == data.size() - 1)
        return mid;
      else
        start = mid + 1;
    }
    return GetLastK(data, k, start, end);
  }
};
