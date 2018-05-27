#include "table.h"

#include <stdio.h>
#include <vector>

int main() {
  int M, N, K;
  scanf("%d %d %d", &M, &N, &K);
  std::vector<int> C(K), D(K);
  for (int i = 0; i < K; ++i) {
    scanf("%d %d", &C[i], &D[i]);
  }
  
  printf("%d\n", countSubsets(M, N, K, C, D));
  return 0;
}
