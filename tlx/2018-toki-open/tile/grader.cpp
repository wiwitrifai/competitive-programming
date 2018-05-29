#include "tile.h"

#include <stdio.h>
#include <vector>

int main() {
  int N, K, M, Q;
  scanf("%d %d %d %d", &N, &K, &M, &Q);
  
  std::vector<int> A(M);
  for (int i = 0; i < M; ++i) {
    scanf("%d", &A[i]);
  }

  init(N, K, Q, M, A);

  for (int i = 0; i < Q; ++i) {
    int L, R;
    scanf("%d %d", &L, &R);
    printf("%d\n", getNumberOfSpecialTiles(L, R));
  }
  return 0;
}
