#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> printMatrix(vector<vector<int>> matrix) {
    vector<int> res;
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return res;
    int start = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    while (2 * start < m && 2 * start < n) {
      printCircle(start, matrix, res);
      start++;
    }
    return res;
  }

  void printCircle(int start, vector<vector<int>> &matrix, vector<int> &path) {
    int m = matrix.size();
    int n = matrix[0].size();
    int endX = m - start - 1;
    int endY = n - start - 1;
    for (int i = start; i <= endY; i++)
      path.push_back(matrix[start][i]);

    for (int i = start + 1; i <= endX; i++)
      path.push_back(matrix[i][endY]);

    if (start < endX)
      for (int i = endY - 1; i >= start; i--)
        path.push_back(matrix[endX][i]);

    if (start < endY)
      for (int i = endX - 1; i >= start + 1; i--)
        path.push_back(matrix[i][start]);
  }
};
