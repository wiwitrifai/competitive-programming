#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int x[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int p, a, b, c, d;
    scanf("%d %d %d %d %d", &p, &a, &b, &c, &d);
    --a; --b;
    x[a][b] ^= p;
    x[a][d] ^= p;
    x[c][b] ^= p;
    x[c][d] ^= p;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", x[i][j], (j == n-1) ? '\n' : ' ');
      x[i+1][j] ^= x[i][j];
      x[i][j+1] ^= x[i][j];
      x[i+1][j+1] ^= x[i][j];
    }
  }
  return 0;
}