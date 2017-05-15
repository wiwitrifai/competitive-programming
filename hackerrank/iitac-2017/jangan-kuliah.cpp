#include <bits/stdc++.h>

using namespace std;

const int N = 2017;
int lef[N][N], rig[N][N];
int s[N], f[N];

int main() {
  int n, q, k, m;
  scanf("%d", &n);
  assert(1 <= n && n <= 2000);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", s+i, f+i);
    assert(1 <= s[i] && s[i] <= 1000);
    assert(1 <= f[i] && f[i] <= 1000);
  }
  memset(lef, 0, sizeof lef);
  memset(rig, 0, sizeof rig);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i]; j++)
      lef[i+1][j] = lef[i][j];
    for (int j = s[i]; j < N; j++) {
      lef[i+1][j] = max(lef[i][j], lef[i][j-s[i]] + f[i]);
    }
    for (int j = 0; j + 1 < N; j++)
      lef[i+1][j+1] = max(lef[i+1][j+1], lef[i+1][j]);
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < s[i]; j++)
      rig[i][j] = rig[i+1][j];
    for (int j = s[i]; j < N; j++) {
      rig[i][j] = max(rig[i+1][j], rig[i+1][j-s[i]] + f[i]);
    }
    for (int j = 0; j + 1 < N; j++)
      rig[i][j+1] = max(rig[i][j+1], rig[i][j]);
  }
  scanf("%d", &q);
  assert(1 <= q && q <= 1000);
  while (q--) {
    scanf("%d %d", &m, &k);
    assert(1 <= k && k <= n);
    assert(1 <= m && m <= 2000);
    k--;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
      ans = max(ans, lef[k][i]+rig[k+1][m-i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}