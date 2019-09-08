#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;

int dp[N];
long long val[N];
long long a[N];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int u, v;
    long long x;
    scanf("%d %d %lld", &u, &v, &x);
    --u, --v;
    a[u] ^= x;
    a[v] ^= x;
  }
  int nmask = 1 << n;
  for (int mask = 1; mask < nmask; ++mask) {
    int sel = -1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        sel = i;
        break;
      }
    }
    val[mask] = val[mask ^ (1 << sel)] ^ a[sel];
  }
  fill(dp, dp+nmask, N);
  dp[0] = 0;
  for (int mask = 0; mask < nmask; ++mask) {
    int cur = dp[mask] + (val[mask] != 0);
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      upd(dp[mask^(1<<i)], cur);
    }
  }
  printf("%d\n", dp[nmask-1]);
  return 0;
}
