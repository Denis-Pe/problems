#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int surfaceArea(vector<vector<int>> &grid) {
    int result = 0;
    size_t size = grid.size();
    size_t lastIdx = size - 1;

    int center, above, below, left, right;
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        center = grid[i][j];
        if (center == 0)
          continue;

        if (i == 0) {
          above = 0;
        } else {
          above = grid[i - 1][j];
        }
        if (i == lastIdx) {
          below = 0;
        } else {
          below = grid[i + 1][j];
        }
        if (j == 0) {
          left = 0;
        } else {
          left = grid[i][j - 1];
        }
        if (j == lastIdx) {
          right = 0;
        } else {
          right = grid[i][j + 1];
        }

        result += center * 6 
          - (center - 1) * 2 
          - min(center, above) 
          - min(center, below) 
          - min(center, left) 
          - min(center, right);
      }
    }

    return result;
  }
};

int main() {
  Solution s;

  vector<vector<int>> grid1 = {{1, 2}, {3, 4}};
  vector<vector<int>> grid2 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> grid3 = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  vector<vector<int>> grid4 = {};
  vector<vector<int>> grid5 = {{1, 2}, {3, 4}};

  cout << s.surfaceArea(grid1) << endl;
  cout << s.surfaceArea(grid2) << endl;
  cout << s.surfaceArea(grid3) << endl;
  cout << s.surfaceArea(grid4) << endl;
  cout << s.surfaceArea(grid5) << endl;

  return 0;
}
