#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct {
  int *buf;
  size_t size;
  size_t capacity;
} Dynar;

Dynar dynar_make(size_t capacity) {
  int *buf = malloc(capacity * sizeof(int));
  Dynar result = {buf, 0, capacity};
  return result;
}

void dynar_push(Dynar *dynar, int value) {
  if (dynar->size == dynar->capacity) {
    int *new_buf =
        realloc(dynar->buf,
                (dynar->capacity == 0 ? 8 : dynar->capacity * 2) * sizeof(int));
    dynar->buf = new_buf;
  }

  dynar->buf[dynar->size] = value;
  dynar->size += 1;
}

void maxLevelHelper(struct TreeNode *node, int level, Dynar *dynar) {
  if (level <= dynar->size) {
    dynar->buf[level - 1] += node->val;
  } else {
    dynar_push(dynar, node->val);
  }
  struct TreeNode *left = node->left;
  struct TreeNode *right = node->right;

  if (left) {
    maxLevelHelper(left, level + 1, dynar);
  }
  if (right) {
    maxLevelHelper(right, level + 1, dynar);
  }
}

int maxLevelSum(struct TreeNode *root) {
  Dynar dynar = dynar_make(32); // used as a map where the key is level - 1

  maxLevelHelper(root, 1, &dynar);

  int max = INT_MIN;
  int max_level = 0;
  for (int i = 0; i < dynar.size; i++) {
    int sum = dynar.buf[i];
    if (sum > max) {
      max = sum;
      max_level = i;
    }
  }

  free(dynar.buf);

  return max_level + 1;
}

int main() {
  struct TreeNode root = {1, NULL, NULL};
  struct TreeNode left = {7, NULL, NULL};
  struct TreeNode right = {0, NULL, NULL};
  struct TreeNode leftleft = {7, NULL, NULL};
  struct TreeNode leftright = {-8, NULL, NULL};
  left.left = &leftleft;
  left.right = &leftright;
  root.left = &left;
  root.right = &right;

  printf("%d\n", maxLevelSum(&root));

  return 0;
}
