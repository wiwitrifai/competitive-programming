/**
 *  ACM ICPC Regional Jakarta 2016 - K : Super Sum
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 15, mod = 1e9 + 7, inv2 = (mod + 1) / 2;
long long dp[N], cnt[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    int m = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      m = max(32 - __builtin_clz(x), m);
      cnt[x]++;
    }
    dp[0] = 1;
    int mmask = 1 << m;
    long long ans = -n;
    for (int i = 1; i < mmask; i++) {
      long long res = 0;
      int blast = i & -i;
      for (int j = i; j; j = (j-1) & i) if (j & blast)
        res = (res + cnt[j] * dp[i^j]) % mod;
      dp[i] = res;
      ans = (ans + res) % mod;
    }
    if (ans < 0)
      ans += mod;
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}