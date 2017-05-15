#include "jump.h"

#include <stdio.h>
#include <string>
#include <vector>

void getString(int size, std::string &S) {
  char temp[size + 3];
  scanf("%s", temp);
  S = temp;
}

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  std::string S;
  getString(N, S);
  std::vector<int> L(Q), R(Q), K(Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d %d %d", &L[i], &R[i], &K[i]);
  }
  std::vector<int> ans = getMinimumPoints(N, Q, S, L, R, K);
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
