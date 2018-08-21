#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> go = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  bool hasPath(char *matrix, int rows, int cols, char *str) {
    if (matrix == NULL || str == NULL)
      return false;
    bool found = false;
    vector<bool> visited(rows * cols, false);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        visited[i * cols + j] = true;
        dfs(matrix, rows, cols, str, i, j, visited, found);
        if (found)
          return true;
        visited[i * cols + j] = false;
      }
    }
    return false;
  }

  void dfs(char *matrix, int rows, int cols, char *str, int x, int y,
           vector<bool> &visited, bool &found) {
    if (found || *str == '\0' ||
        (*str == matrix[x * cols + y] && *(str + 1) == '\0')) {
      found = true;
      return;
    }

    if (*str == matrix[x * cols + y]) {
      for (int i = 0; i < 4; i++) {
        int new_x = x - go[i][0];
        int new_y = y - go[i][1];

        if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols)
          continue;
        if (visited[new_x * cols + new_y])
          continue;

        visited[new_x * cols + new_y] = true;
        dfs(matrix, rows, cols, str + 1, new_x, new_y, visited, found);
        visited[new_x * cols + new_y] = false;
      }
    }
  }
};
