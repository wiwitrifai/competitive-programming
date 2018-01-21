#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N][N], ans[N][N];
int col[N];

bool solve(int n) {
  fill(col, col+n, -1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (a[i][j] != a[j][i]) return 0;
    }
  for (int i = 0, c = 0; i < n; ++i) {
    if (a[i][i] == 0) {
      for (int j = 0; j < n; ++j)
        if (a[i][j] != 0) return 0;
    }
    else if (a[i][i] == -1) return 0;
    else {
      if (col[i] == -1) {
        ans[i][c] = -1;
        for (int j = 0; j < n; ++j) {
          if (a[i][j] == 0) continue;
          if (col[j] != -1) return 0;
          col[j] = c;
          ans[j][c] = a[i][j] * ans[i][c];
        }
        ++c;
      }
      for (int j = 0; j < n; ++j) {
        if (col[j] == col[i]) {
          if (a[i][j] != ans[i][col[i]] * ans[j][col[i]]) return 0;
        }
        else {
          if (a[i][j] != 0) return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", a[i]+j), ans[i][j] = 0;
    bool ok = solve(n);
    if (ok) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          printf("%d%c", ans[i][j], j == n-1 ? '\n' : ' ');
    }
    else
      puts("-1");
  }
  return 0;
}