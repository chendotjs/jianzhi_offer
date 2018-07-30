#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void replaceSpace(char *str, int length) {
    int space_num = 0;
    for (int i = 0; i < length; i++)
      if (str[i] == ' ')
        space_num++;

    int new_length = length + 2 * space_num;
    int i = length - 1, j = new_length - 1;
    while (i >= 0) {
      if (str[i] == ' ') {
        str[j--] = '0';
        str[j--] = '2';
        str[j--] = '%';
        i--;
      } else {
        str[j--] = str[i--];
      }
    }
  }
};


int main(int argc, char const *argv[]) {
  {
    char str[512] = "We Are Happy";
    Solution().replaceSpace(str, 12);
    cout << str << endl;
  }
  return 0;
}
