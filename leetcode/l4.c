#include <stdbool.h>
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int mid_idx = (nums1Size + nums2Size) / 2;

  int i1 = 0, i2 = 0;
  int value = 0;
  int previous = 0;
  while (1) {
    bool inc1 = false;
    bool inc2 = false;
    if (i1 < nums1Size && i2 < nums2Size) {
      int i1value = nums1[i1];
      int i2value = nums2[i2];

      if (i1value <= i2value) {
        previous = value;
        value = i1value;
        inc1 = true;
      } else {
        previous = value;
        value = i2value;
        inc2 = true;
      }
    } else if (i1 < nums1Size) {
      previous = value;
      value = nums1[i1];
      inc1 = true;
    } else if (i2 < nums2Size) {
      previous = value;
      value = nums2[i2];
      inc2 = true;
    } else {
      break;
    }

    if ((i1 + i2) == mid_idx) {
      if ((nums1Size + nums2Size) % 2 == 0) {
        return (value + previous) / 2.0;
      } else {
        return value;
      }
    }

    if (inc1)
      i1++;
    if (inc2)
      i2++;
  }

  return 0;
}

int main() {
  int nums1[] = {1, 2};
  int nums1Size = 2;
  int nums2[] = {3, 4};
  int nums2Size = 2;
  double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
  printf("%f\n", result);
  return 0;
}
