#include "beauty.h"

#include <stdio.h>
#include <vector>

int main() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  std::vector<int> T(N);
  std::vector<int> U(M), V(M);
  std::vector<int> A(Q), B(Q);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &T[i]);
  }
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &U[i], &V[i]);
  }
  for (int i = 0; i < Q; ++i) {
    scanf("%d %d", &A[i], &B[i]);
  }
  std::vector<int> ans = getMaximumBeauty(N, M, Q, T, U, V, A, B);
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
