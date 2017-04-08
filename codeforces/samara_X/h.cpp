#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int x[N][N];
int ans[N][N];
int tmp[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", x[i]+j);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[i][j] = x[i][j];
      if (i)
        tmp[i][j] = max(tmp[i][j], tmp[i-1][j]);
      if (j)
        tmp[i][j] = max(tmp[i][j], tmp[i][j-1]);
      if (i+1 < n && j+1 < m) {
        ans[i+1][j+1] = max(ans[i+1][j+1], tmp[i][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m-1; j >= 0; j--) {
      tmp[i][j] = x[i][j];
      if (i)
        tmp[i][j] = max(tmp[i][j], tmp[i-1][j]);
      if (j+1 < m)
        tmp[i][j] = max(tmp[i][j], tmp[i][j+1]);
      if (i+1 < n && j-1 >= 0) {
        ans[i+1][j-1] = max(ans[i+1][j-1], tmp[i][j]);
      }
    }
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      tmp[i][j] = x[i][j];
      if (i+1 < n)
        tmp[i][j] = max(tmp[i][j], tmp[i+1][j]);
      if (j)
        tmp[i][j] = max(tmp[i][j], tmp[i][j-1]);
      if (i-1 >= 0 && j+1 < m) {
        ans[i-1][j+1] = max(ans[i-1][j+1], tmp[i][j]);
      }
    }
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--) {
      tmp[i][j] = x[i][j];
      if (i+1 < n)
        tmp[i][j] = max(tmp[i][j], tmp[i+1][j]);
      if (j+1 < m)
        tmp[i][j] = max(tmp[i][j], tmp[i][j+1]);
      if (i-1 >= 0 && j-1 >= 0) {
        ans[i-1][j-1] = max(ans[i-1][j-1], tmp[i][j]);
      }
    }
  }
  int cur = ans[0][0];
  int r = 0, c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] < cur) {
        r = i; c = j;
        cur = ans[i][j];
      }
    }
  }
  printf("%d %d\n", r+1, c+1);
  return 0;
}