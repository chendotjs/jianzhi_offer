#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  priority_queue<int, vector<int>, less<int>> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  void Insert(int num) {
    if (maxHeap.empty() || num <= maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);

    if (maxHeap.size() - minHeap.size() == 2) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() - maxHeap.size() == 1) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double GetMedian() {
    double median = 0;
    if (maxHeap.size() == minHeap.size())
      median = (maxHeap.top() + minHeap.top()) / 2.0;
    else
      median = maxHeap.top();
    return median;
  }
};
