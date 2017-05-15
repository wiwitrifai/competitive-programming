#include "teleport.h"

#include <stdio.h>
#include <vector>

int main() {
  int R, C, K;
  scanf("%d %d %d", &R, &C, &K);
  std::vector<std::vector<int> > T(R);
  std::vector<std::vector<int> > P(R);
  for (int i = 0; i < R; ++i) {
    T[i].resize(C);
    for (int j = 0; j < C; ++j) {
      scanf("%d", &T[i][j]);
    }
  }
  for (int i = 0; i < R; ++i) {
    P[i].resize(C);
    for (int j = 0; j < C; ++j) {
      scanf("%d", &P[i][j]);
    }
  }
  printf("%lld\n", getMaximumPoints(R, C, K, T, P));
  return 0;
}
