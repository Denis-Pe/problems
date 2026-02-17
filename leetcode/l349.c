#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int compareInts(const void* pa, const void* pb) {
  int a = *(int*)pa;
  int b = *(int*)pb;

  return a - b;
}

void sortArr(int* arr, size_t arrSize) {
  qsort(arr, arrSize, sizeof(int), compareInts);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
                  int *returnSize) {
  int* result = malloc(sizeof(int) * (*returnSize));

  sortArr(nums1, nums1Size);
  sortArr(nums2, nums2Size);

  size_t i = 0;
  size_t j = 0;
  size_t l = 0;
  int last = INT_MIN;
  while (i < nums1Size && j < nums2Size) {
    int at1 = nums1[i];
    int at2 = nums2[j];
    if (at1 < at2) {
      i++;
    } else if (at1 > at2) {
      j++;
    } else if (last != at1) {
      result[l++] = at1;
      last = at1;
    } else {
      i++; j++;
    }
  }

  return result;
}

void printArr(int *arr, size_t arrSize) {
  printf("[");
  for (size_t i = 0; i < arrSize - 1; i++) {
    printf("%d, ", arr[i]);
  }
  if (arrSize > 0) {
    printf("%d]\n", arr[arrSize - 1]);
  }
}

int main() {
  int nums1[] = {1, 2, 2, 1};
  int nums2[] = {2, 2};
  int returnSize = 1;

  int *result = intersection(nums1, 4, nums2, 2, &returnSize);

  printArr(result, returnSize);

  free(result);

  return 0;
}
