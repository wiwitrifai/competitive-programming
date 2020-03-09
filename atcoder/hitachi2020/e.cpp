#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int ans[N][N];

int main() {
  for (int n = 1; n * 2 <= N; n *= 2) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i+n][j] = ans[i][j];
        ans[i][j+n] = ans[i][j];
        ans[i+n][j+n] = !ans[i][j];
      }
    }
  }
  for (int i = N-1; i > 0; --i) {
    for (int j = N-1; j > 0; --j) {
      ans[i][j] ^= ans[i-1][j-1] ^ ans[i-1][j] ^ ans[i][j-1];
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  n = 1 << n;
  m = 1 << m;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
