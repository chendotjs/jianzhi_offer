#include <bits/stdc++.h>
using namespace std;

#define DIVISOR 1000000007

class Solution {
public:
  int InversePairs(vector<int> data) {
    return InversePairs(data, 0, data.size() - 1);
  }

  int InversePairs(vector<int> &data, int left, int right) {
    if (left >= right)
      return 0;

    int mid = left + (right - left) / 2;
    int lcnt = InversePairs(data, left, mid) % DIVISOR;
    int rcnt = InversePairs(data, mid + 1, right) % DIVISOR;
    int mixcnt = 0;
    for (int i = mid, j = right; i >= left && j >= mid + 1;) {
      if (data[i] > data[j]) {
        mixcnt += j - (mid + 1) + 1;
        mixcnt %= DIVISOR;
        i--;
      } else
        j--;
    }

    // below is sort part
    vector<int> tmp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
      if (data[i] < data[j])
        tmp.push_back(data[i++]);
      else
        tmp.push_back(data[j++]);
    }
    while (i <= mid)
      tmp.push_back(data[i++]);
    while (j <= right)
      tmp.push_back(data[j++]);

    for (int i = 0; i < tmp.size(); i++)
      data[left + i] = tmp[i];

    return (lcnt + rcnt + mixcnt) % DIVISOR;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {2, 1};
    cout << Solution().InversePairs(vec) << endl;
  }

  {
    vector<int> vec = {1, 2};
    cout << Solution().InversePairs(vec) << endl;
  }

  {
    vector<int> vec = {3, 2, 1};
    cout << Solution().InversePairs(vec) << endl;
  }

  {
    vector<int> vec = {7, 5, 6, 4};
    cout << Solution().InversePairs(vec) << endl;
  }
  return 0;
}
