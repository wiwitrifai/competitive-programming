#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long a[N][N], b[N][N];

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      scanf("%lld", a[i]+j);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] > a[i][j]) {
        puts("TIDAK");
        return 0;
      }
      long long add = a[i][j] - b[i][j];
      if (add > 0) {
        if (i + p > n || j + p > m) {
          puts("TIDAK");
          return 0;
        }
        b[i][j] += add;
        b[i+p][j] -= add;
        b[i][j+p] -= add;
        b[i+p][j+p] += add;
      }
      b[i+1][j] += b[i][j];
      b[i][j+1] += b[i][j];
      b[i+1][j+1] -= b[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        puts("TIDAK");
        return 0;
      }
    }
  }
  puts("YA");
  return 0;
}
