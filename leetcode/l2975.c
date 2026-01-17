#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MODULO 1000000007L

int maximizeSquareAreaOLD(int m, int n, int *hFences, int hFencesSize,
                          int *vFences, int vFencesSize) {
  if (m == n) {
    return ((long)(m - 1) * (n - 1)) % MODULO;
  }
  int longest_edge = m > n ? m : n;
  bool *h_differences = calloc(longest_edge, sizeof(bool));
  bool *v_differences = calloc(longest_edge, sizeof(bool));
  h_differences[m - 1] = true;
  v_differences[n - 1] = true;

  clock_t c1, c2;
  c1 = clock();
  for (int i = 0; i < hFencesSize; i++) {
    h_differences[hFences[i] - 1] = true;
    h_differences[m - hFences[i]] = true;
    for (int j = i + 1; j < hFencesSize; j++) {
      h_differences[abs(hFences[j] - hFences[i])] = true;
    }
  }
  printf("1 %ld\n", clock() - c1);

  c1 = clock();
  for (int i = 0; i < vFencesSize; i++) {
    v_differences[vFences[i] - 1] = true;
    v_differences[n - vFences[i]] = true;
    for (int j = i + 1; j < vFencesSize; j++) {
      v_differences[abs(vFences[j] - vFences[i])] = true;
    }
  }
  printf("2 %ld\n", clock() - c1);

  c1 = clock();
  for (long long i = longest_edge - 1; i >= 1; i--) {
    if (h_differences[i] && v_differences[i]) {
      printf("3 %ld\n", clock() - c1);
      free(h_differences);
      free(v_differences);
      return (i * i) % MODULO;
    }
  }

  return -1;
}

void toggle_h_edge(char *edge) { *edge |= 0x1; }

void toggle_v_edge(char *edge) { *edge |= 0x10; }

int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize,
                       int *vFences, int vFencesSize) {
  if (m == n) {
    return ((long)(m - 1) * (n - 1)) % MODULO;
  }
  int longest_edge = m > n ? m : n;
  char *edges = calloc(longest_edge, sizeof(char));

  clock_t c1;
  c1 = clock();
  for (int i = 0; i < hFencesSize; i++) {
    toggle_h_edge(edges + hFences[i] - 1);
    toggle_h_edge(edges + m - hFences[i]);
    for (int j = i + 1; j < hFencesSize; j++) {
      toggle_h_edge(edges + abs(hFences[j] - hFences[i]));
    }
  }
  printf("1 %ld\n", clock() - c1);

  c1 = clock();
  unsigned long long max_edge = 0;
  for (int i = 0; i < vFencesSize; i++) {
    int vminus1 = vFences[i] - 1;
    toggle_v_edge(edges + vminus1);
    printf("vminus1 %d %llu\n", vminus1, max_edge);
    int nminusv = n - vFences[i];
    toggle_v_edge(edges + nminusv);
    printf("nminusv %d %llu\n", nminusv, max_edge);
    for (int j = i + 1; j < vFencesSize; j++) {
      int vjminusvi = abs(vFences[j] - vFences[i]);
      toggle_v_edge(edges + vjminusvi);
      printf("vjminusvi %d %llu\n", vjminusvi, max_edge);

      if (edges[vjminusvi] == 0x11 && vjminusvi > max_edge) {
        max_edge = vjminusvi;
      }
    }
    if (edges[vminus1] == 0x11 && vminus1 > max_edge) {
      max_edge = vminus1;
    }
    if (edges[nminusv] == 0x11 && nminusv > max_edge) {
      max_edge = nminusv;
    }
  }
  int mminus1 = m - 1;
  toggle_h_edge(edges + mminus1);
  if (edges[mminus1] == 0x11 && mminus1 > max_edge) {
    max_edge = mminus1;
  }
  int nminus1 = n - 1;
  toggle_v_edge(edges + nminus1);
  if (edges[nminus1] == 0x11 && nminus1 > max_edge) {
    max_edge = nminus1;
  }
  printf("2 %ld\n", clock() - c1);

  free(edges);

  printf("Edge: %lld\n", max_edge);

  return max_edge == 0 ? -1 : (max_edge * max_edge) % MODULO;
}

int main(int argc, char **argv) {
  int m = 4, n = 3, hFencesSize = 2, vFencesSize = 1;
  int hFences[] = {2, 3};
  int vFences[] = {2};

  int result =
      maximizeSquareArea(m, n, hFences, hFencesSize, vFences, vFencesSize);

  printf("%d\n", result);

  return 0;
}
