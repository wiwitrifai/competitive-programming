#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, Q = 105;

int a[N];
int k[Q];
int kk[Q];
int ans[Q][N];

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i)
    scanf("%d", k+i), kk[i] = k[i];
  sort(kk, kk+q);
  int m = unique(kk, kk+q) - kk;
  kk[m] = -1;
  memset(ans, 0, sizeof ans);
  for (int len = n-l; len > 0; --len) {
    int cnt = 0;
    for (int i = n-1-len, j = n-1; i >= 0; --i, --j) {
      if (j + l < n) {
        cnt -= a[i+l] != a[j+l];
      }
      cnt += a[i] != a[j];
      if (j + l <= n) {
        int id = lower_bound(kk, kk+m, cnt) - kk;
        ++ans[id][i];
        ++ans[id][j];
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j+l <= n; ++j)
      ans[i+1][j] += ans[i][j];
  }
  for (int i = 0; i < q; ++i) {
    int id = lower_bound(kk, kk+m, k[i]) - kk;
    for (int j = 0; j+l <= n; ++j)
      printf("%d%c", ans[id][j], j+l == n ? '\n' : ' ');
  }
  return 0;
}