#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int ans[N][N];

int main() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a; ++j) {
      ans[i][j] ^= 1;
    }
  }
  for (int i = 0; i < b; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[i][j] ^= 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
