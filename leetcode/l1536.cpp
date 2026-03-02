#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <set>
#include <string.h>

using namespace std;

uint8_t frequencies[26] = {0};

class Solution {
public:
  bool equalFrequency(string word) {
    for (auto c : word) {
      char fIndex = c - 97;
      frequencies[fIndex] += 1;
    }

    uint8_t decrements = 0;
    uint8_t prev = 0;
    for (char i = 0; i < 26; i++) {
      uint8_t freq = frequencies[i];
      if (freq == 0) {
        continue;
      }
      if (prev == 0) {
        prev = freq;
        continue;
      }
      if (prev + 1 == freq || prev == freq + 1) {
        decrements++;
      }

      if (decrements == 2) {
        return false;
      }
    }

    if (decrements == 0) {
      return false;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();

  cout << s.equalFrequency("aca") << endl;// << s.equalFrequency("aazz") << endl;

  return 0;
}
