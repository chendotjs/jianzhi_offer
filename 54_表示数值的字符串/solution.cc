#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isNumeric(char *string) {
    if (string == NULL)
      return false;

    const int INVALID = 0;
    const int SPACE = 1;
    const int SIGN = 2;
    const int DIGIT = 3;
    const int DOT = 4;
    const int EXPONENT = 5;

    vector<vector<int>> transitionTable = {
        {-1, 0, 3, 1, 2, -1},    // 0，no input or just spaces
        {-1, 8, -1, 1, 4, 5},    // 1 input is digits
        {-1, -1, -1, 4, -1, -1}, // 2 no digits in front just Dot
        {-1, -1, -1, 1, 2, -1},  // 3 sign
        {-1, 8, -1, 4, -1, 5},   // 4 digits and dot in front
        {-1, -1, 6, 7, -1, -1},  // 5 input 'e' or 'E'
        {-1, -1, -1, 7, -1, -1}, // 6 after 'e' input sign
        {-1, 8, -1, 7, -1, -1},  // 7 after 'e' input digits
        {-1, 8, -1, -1, -1, -1}  // 8 after valid input input space
    };
    int state = 0;
    int input = 0;
    while (*string != '\0') {
      switch (*string) {
      case ' ':
        input = SPACE;
        break;
      case '0' ... '9':
        input = DIGIT;
        break;
      case '+':
      case '-':
        input = SIGN;
        break;
      case '.':
        input = DOT;
        break;
      case 'e':
      case 'E':
        input = EXPONENT;
        break;
      default:
        input = INVALID;
      }
      state = transitionTable[state][input];
      if (state == -1)
        return false;
      string++;
    }
    return (state == 1 || state == 4 || state == 7 || state == 8) ? true
                                                                  : false;
  }
};
