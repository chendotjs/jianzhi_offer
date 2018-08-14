#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool match(char *str, char *pattern) {
    if (str == NULL || pattern == NULL)
      return false;
    if (*str == '\0' && *pattern == '\0')
      return true;
    if (*pattern == '\0' && *str != '\0')
      return false;
    if (*str == '\0' && *(pattern + 1) != '*')
      return false;

    if (*(pattern + 1) != '*') {
      if (isalnum(*pattern))
        return *str == *pattern ? match(str + 1, pattern + 1) : false;
      if (*pattern == '.')
        return match(str + 1, pattern + 1);
    } else if (*(pattern + 1) == '*') {
      if (*pattern == *str || (*pattern == '.' && *str != '\0'))
        return match(str + 1, pattern) || match(str + 1, pattern + 2) ||
               match(str, pattern + 2);
      return match(str, pattern + 2);
    }
    return false;
  }
};


int main(int argc, char const *argv[]) {
  {
    cout << Solution().match("abc", ".*") << endl;
  }
  return 0;
}
