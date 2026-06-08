#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      vector<int> result(nums.size());

      int head = 0, tail = nums.size() - 1;

      for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];

        if (n < pivot) {
          result[head++] = n;
        }
      }

      for (int i = nums.size() - 1; i >= 0; i--) {
        int n = nums[i];

        if (n > pivot) {
          result[tail--] = n;
        }
      }        

      for (; head <= tail; head++) {
        result[head] = pivot;
      }

      return result;
    }
};

int main() {

}
