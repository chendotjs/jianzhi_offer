#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> go = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int movingCount(int threshold, int rows, int cols) {
    int count = 0;
    if (threshold < 0 || rows <= 0 || cols <= 0)
      return count;

    queue<pair<int, int>> Q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    Q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (Q.empty() == false) {
      auto cur = Q.front();
      Q.pop();
      count++;
      for (int i = 0; i < 4; i++) {
        int nx = cur.first + go[i][0];
        int ny = cur.second + go[i][1];
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || visited[nx][ny])
          continue;
        if (digitSum(nx) + digitSum(ny) > threshold)
          continue;
        visited[nx][ny] = true;
        Q.push(make_pair(nx, ny));
      }
    }
    return count;
  }

  int digitSum(int num) {
    int sum = 0;
    while (num != 0) {
      sum += (num % 10);
      num /= 10;
    }
    return sum;
  }
};
