#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEN_RAISED_NINTH 1000000000

int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize,
                       int *vFences, int vFencesSize) {
  if (m == n) {
    return ((long)(m - 1) * (n - 1)) % TEN_RAISED_NINTH;
  }

  int max_area = -1; // mod 10^9
  // lookup maps
  bool *h_map = calloc(601, sizeof(bool));
  bool *v_map = calloc(601, sizeof(bool));
  for (int hi = 0; hi < hFencesSize; hi++) {
    h_map[hFences[hi]] = true;
  }
  for (int vi = 0; vi < vFencesSize; vi++) {
    v_map[vFences[vi]] = true;
  }

  for (int i = 0; i < m; i++) {
    // TODO iterate through each square of the area, accumulating into possible
    // areas, looking up possible fences. After that, one possible approach to
    // start removing fences is recursion. Another possible approach is
    // accumulating possible areas, then iterating over them and try to find
    // possible squares. For now, recursion sounds better and easier
  }

  return -1;
}

int main(int argc, char **argv) {
  int m = 4, n = 3, hFencesSize = 2, vFencesSize = 1;
  int hFences[] = {2, 3};
  int vFences[] = {1};

  int result =
      maximizeSquareArea(m, n, hFences, hFencesSize, vFences, vFencesSize);

  printf("%d\n", result);

  return 0;
}
