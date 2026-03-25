#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> map(s.size());
    vector<char> taken(s.size());

    for (size_t i = 0; i < s.size(); i++) {
      auto schar = s[i];
      auto tchar = t[i];

      if (auto it = map.find(schar); it != map.end()) {
        if (it->second != tchar) {
          return false;
        }
      } else {
        for (size_t j = 0; j < taken.size(); j++) {
          if (taken[j] == tchar) {
            return false;
          }
        }
        taken.push_back(tchar);
        map[schar] = tchar;
      }
    }

    return true;
  }
};

int main() {
  string a = "badc", b = "baba";
  Solution s;

  cout << "Result: " << s.isIsomorphic(a, b) << endl;
}
