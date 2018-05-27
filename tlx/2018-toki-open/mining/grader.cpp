#include "mining.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int X, Y;
static const int M = 1000;
static const int N = 1000;
static int number_of_queries = 0;

static bool isPerfectSquare(int K) {
  static const int square_check_offset = 3;
  int sqrt_K = (int)round(sqrt(K));
  for (int i = sqrt_K - square_check_offset;
       i <= sqrt_K + square_check_offset; ++i) {
    if (i * i == K) {
      return true;
    }
  }
  return false;
}

bool isIntegerDistance(int A, int B) {
  if (A < 1 || A > M) {
    printf("WA: The first coordinate is not between 1 and %d\n", M);
    exit(0);
  }
  if (B < 1 || B > N) {
    printf("WA: The second coordinate is not between 1 and %d\n", N);
    exit(0);
  }
  ++number_of_queries;
  return isPerfectSquare((A - X) * (A - X) + (B - Y) * (B - Y));
}

void answer(int A, int B) {
  if (A != X || B != Y) {
    printf("WA: You guessed the wrong coordinate\n");
    exit(0);
  }
  printf("OK: You called isIntegerDistance(A, B) %d times\n",
         number_of_queries);
  exit(0);
}

int main() {
  scanf("%d %d", &X, &Y);

  findGold();

  printf("WA: findGold() must call answer(A, B) method\n");
  return 0;
}
