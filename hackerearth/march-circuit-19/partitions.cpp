#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long sum[N];
long long a[N];
long long dp[N];

int main() {
  int n;
  long long l, r;
  scanf("%d %lld %lld", &n, &l, &r);
  --l;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    sum[i+1] = sum[i] + a[i];
  }
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 1, lef = 0, rig = 0; i <= n; ++i) {
    while (sum[i] - sum[rig] > l) ++rig;
    while (sum[i] - sum[lef] > r) ++lef;
    dp[i+1] = (dp[i] + dp[rig] - dp[lef]) % mod;
    if (dp[i+1] < 0)
      dp[i+1] += mod;
  }
  long long ans = dp[n+1] - dp[n];
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
