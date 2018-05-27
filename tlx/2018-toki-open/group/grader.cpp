#include "group.h"

#include <stdio.h>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &X[i], &Y[i]);
  }

  printf("%d\n", getMinimumDelay(N, X, Y));
  return 0;
}
