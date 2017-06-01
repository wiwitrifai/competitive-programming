#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const long long N = 2e6 + 6;

int n, k;
long long m, C[12][12], I[12];

long long powmod(long long b, long long p) {
  b %= mod;
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
} 

long long dp[N];

int main() {
  for (int i = 0; i < 12; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    I[i] = powmod(i, mod-2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %lld", &n, &k, &m);
    vector< long long > vx;
    vx.push_back(0);
    for (long long i = 1; i * i <= m; i++) {
      vx.push_back(i);
      long long j = m/i;
      if (i != j)
        vx.push_back(j); 
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    dp[0] = 0;
    for (int i = 1; i < vx.size(); i++)
      dp[i] = 1;
    for (int z = 0; z < n; z++) {
      long long s;
      scanf("%lld", &s);
      long long sk = powmod(s, k);
      int j = lower_bound(vx.begin(), vx.end(), m/s) - vx.begin();
      for (int i = (int)vx.size()-1; i >= 0; i--) {
        while (j > 0 && vx[j] * s > vx[i]) j--;
        dp[i] = (dp[i] - ((dp[j] * sk) % mod)) % mod;
        if (dp[i] < 0)
          dp[i] += mod;
      }
    }
    long long ans = 0;
    for (int z = 1; z < vx.size(); z++) {
      long long mul = (dp[z]-dp[z-1]) % mod;
      if (mul == 0)
        continue;
      long long mm = (m / vx[z]) % mod;
      long long mm1 = (mm + 1) % mod;
      long long ss[12];
      ss[0] = mm;
      ss[1] = (((mm * mm1) % mod) * I[2]) % mod;
      long long mmi = (mm1 * mm1) % mod;
      for (int i = 2; i <= k; i++) {
        mmi = (mmi * mm1) % mod;
        long long sum = 0;
        for (int j = 0; j < i; j++) {
          sum = (sum + C[i+1][j] * ss[j]) % mod;
        }
        ss[i] = ((mmi - 1 - sum) * I[i+1]) % mod;
        if (ss[i] < 0)
          ss[i] += mod;
      }
      ans = (ans + mul * ss[k]) % mod;
    }
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}