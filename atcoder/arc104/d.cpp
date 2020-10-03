#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int dp[N][N * N * N], cnt[N];
int n, k, mod;

void upd(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  scanf("%d %d %d", &n, &k, &mod);
  dp[0][0] = 1;
  int sum = 0;
  for (int x = 1; x <= n; ++x) {
    memset(cnt, 0, sizeof cnt);
    sum += k * x;
    int full = k * x;
    for (int j = 0, z = 0; j <= sum; ++j) {
      int now = dp[x-1][j];
      upd(cnt[z], now);
      dp[x][j] = cnt[z];
      if (j >= full) {
        upd(cnt[z], mod - dp[x-1][j-full]);
      }
      ++z;
      if (z >= x)
        z -= x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int lef = i - 1, rig = n - i;
    long long ans = 0;
    for (int j = 0; j <= sum; ++j) {
      ans = (ans + 1LL * dp[lef][j] * dp[rig][j]) % mod;
    }
    ans = (ans * (k+1) - 1) % mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
