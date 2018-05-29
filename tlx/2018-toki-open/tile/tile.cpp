#include "tile.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 44;

int to[LG][N], up;
vector<int> A;

void init(int N, int K, int Q, int M, std::vector<int> A) {
  ::A = A;
  int ma = (A.back()-A[0] + K) / K;
  for (int i = 0, j = 0; i < M; ++i) {
    while (j < M && A[j]-A[i] < K) ++j;
    to[0][i] = j;
  }
  to[0][M] = M;
  for (int i = 0;; ++i) {
    up = i;
    if (to[i][0] == M) break;
    for (int j = 0; j <= M; ++j) {
      to[i+1][j] = to[i][to[i][j]];
    }
  }
}

int getNumberOfSpecialTiles(int L, int R) {
  int ans = 0;
  int le = lower_bound(A.begin(), A.end(), L) - A.begin();
  int ri = upper_bound(A.begin(), A.end(), R) - A.begin();
  for (int i = up; i >= 0; --i) {
    if (to[i][le] < ri) {
      ans += (1 << i), le = to[i][le];
    }
  }
  if (le < ri)
    ++ans;
  return ans;
}
