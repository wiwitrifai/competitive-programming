#include <bits/stdc++.h>

using namespace std;

const int N = 505, mod = 1e9 + 7;

long long dp[2][N][105], sum[N][105], sumq[N][105];
int a[N];

void add(long long & var, long long val) {
  var = (var + val) % mod;
  if (var < 0)
    var += mod;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  reverse(a, a+n);
  int c = 0, b = 1;
  dp[c][a[0]][1] = 1;
  int tot = a[0];
  for (int z = 1; z < n; ++z) {
    swap(b, c);
    int l = a[z];
    tot = min(tot + l, x);
    for (int i = 0; i <= tot; ++i)
      for (int j = 0; j <= z+1; ++j) {
        dp[c][i][j] = 0;
        sum[i+1][j] = (sum[i][j] + dp[b][i+1][j]) % mod;
        sumq[i+1][j] = (sumq[i][j] + 1LL * (i+1) * dp[b][i+1][j]) % mod;
      }
    for (int p = l; p <= tot; ++p) {
      for (int q = 1; q <= z+1; ++q) {
        long long & now = dp[c][p][q];
        add(now, dp[b][p-l][q-1] * q);
        long long cnt = p - (l - 1) * q;
        if (cnt > 0) {
          add(now, dp[b][p][q] * cnt);
        }
        add(now, 2LL * q * (sum[p-1][q] - sum[p-l][q]));
        long long A = (sumq[p][q+1] - sumq[p-l+1][q+1]), B = sum[p][q+1] - sum[p-l+1][q+1];
        long long cur = (A + B * (l-p-1)) % mod;
        add(now, cur * q);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    add(ans, dp[c][x][i]);
  printf("%lld\n", ans);
  return 0;
}
