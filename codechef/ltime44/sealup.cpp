#include <bits/stdc++.h>

using namespace std;

const int N = 2017, D = 2e6 + 6;
const long long inf = 1e17;

int n, m;
long long x[N], y[N];
long long l[N], c[N];
long long dp[D];
long long solve(int d) {
  if (d <= 0)
    return 0;
  if (dp[d] >= 0)
    return dp[d];
  long long &ret = dp[d];
  ret = inf;
  for (int i = 0; i < m; i++)
    ret = min(ret, solve(d-l[i]) + c[i]);
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", x+i, y+i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%lld %lld", l+i, c+i);
    }
    long long xl = x[n-1], yl = y[n-1];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long dx = x[i]-xl, dy = y[i]-yl;
      long long d2 = dx * dx + dy * dy;
      long long dd = sqrt(d2);
      if (dd * dd < d2)
        dd++;
      ans += solve(dd);
      xl = x[i], yl = y[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}