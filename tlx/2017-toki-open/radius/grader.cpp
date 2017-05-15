#include "radius.h"

#include <stdio.h>
#include <vector>

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  std::vector<int> U(N - 1), V(N - 1);
  std::vector<int> A(Q);
  for (int i = 0; i < N - 1; ++i) {
    scanf("%d %d", &U[i], &V[i]);
  }
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &A[i]);
  }
  std::vector<int> ans = getRadius(N, Q, U, V, A);
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
