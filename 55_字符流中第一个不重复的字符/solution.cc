#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  Solution() : map(256, 0){};
  vector<int> map;
  list<char> candidate;

  // Insert one char from stringstream
  void Insert(char ch) {
    ++map[ch];
    if (map[ch] == 1) {
      candidate.push_back(ch);
    } else {
      auto it = find(candidate.begin(), candidate.end(), ch);
      if (it != candidate.end())
        candidate.erase(it);
    }
  }
  // return the first appearence once char in current stringstream
  char FirstAppearingOnce() {
    char res = candidate.size() > 0 ? *candidate.begin() : '#';
    return res;
  }
};

int main(int argc, char const *argv[]) {
  {
    string str = "google";
    Solution s;
    for (auto c : str) {
      s.Insert(c);
      cout << s.FirstAppearingOnce() << endl;
    }
  }
  return 0;
}
