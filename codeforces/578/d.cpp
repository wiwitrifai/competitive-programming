#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

char grid[N][N];

int rows[N][N], cols[N][N];
int fullr[N], fullc[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s", grid[i]);
  for (int i = 0; i < n; ++i) {
    int le = n, ri = -1;
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 'B') {
        le = min(le, j);
        ri = max(ri, j);
      }
    }
    fullr[i] = (le > ri);
    for (int j = max(0, ri-k+1); j <= min(le, n-1); ++j) {
      rows[i][j] = 1;
    }
    ri = -1, le = n;
    for (int j = 0; j < n; ++j) {
      if (grid[j][i] == 'B') {
        le = min(le, j);
        ri = max(ri, j);
      }
    }
    fullc[i] = (le > ri);
    for (int j = max(0, ri-k+1); j <= min(le, n-1); ++j) {
      cols[j][i] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      int cur = cols[i][j];
      cols[i][j] = cnt;
      cnt += cur;
    }
    cols[i][n] = cnt;
    cnt = 0;
    for (int j = 0; j < n; ++j) {
      int cur = rows[j][i];
      rows[j][i] = cnt;
      cnt += cur;
    }
    rows[n][i] = cnt;
  }
  int ans = 0;
  int addr = 0;
  for (int i = k; i < n; ++i)
    addr += fullr[i];
  for (int i = 0; i + k <= n; ++i) {
    int addc = addr;
    for (int j = k; j < n; ++j)
      addc += fullc[j];
    for (int j = 0; j + k <= n; ++j) {
      ans = max(ans, cols[i][j+k] - cols[i][j] + rows[i+k][j] - rows[i][j] + addc);
      addc += fullc[j] - fullc[j+k];
    }
    addr += fullr[i] - fullr[i+k];
  }
  printf("%d\n", ans);
  return 0;
}
