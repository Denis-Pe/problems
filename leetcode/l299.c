#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define START_DIGITS 48

char *getHint(char *secret, char *guess) {
  int demand[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int supply[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int bulls = 0;
  for (int i = 0; secret[i] != '\0'; i++) {
    char csecret = secret[i];
    char cguess = guess[i];
    if (csecret == cguess) {
      bulls++;
    } else {
      demand[((int)csecret) - START_DIGITS] += 1;
      supply[((int)cguess) - START_DIGITS] += 1;
    }
  }

  int cows = 0;
  for (int i = 0; i < 10; i++) {
    int d = demand[i], s = supply[i];
    int increment = d >= s ? s : d;
    cows += increment;
  }

  char *result = malloc(
      11); // 4 digits times two, plus two more for the A and B, plus one for \0
  sprintf(result, "%dA%dB", bulls, cows);

  return result;
}

int main() {

  char *secret = "1123";
  char *guess = "0111";
  char *result = getHint(secret, guess);

  printf("%s\n", result);

  free(result);

  return 0;
}
