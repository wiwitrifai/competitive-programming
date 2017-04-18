#include <bits/stdc++.h>

using namespace std;

const int N = 1e6, M = N + 5, mod = 1e9 + 7;

int dp[M], a[M];
int sum2[M], sumd[M], sum[M], cnt[M];

long long powmod(long long b, long long pw) {
  long long ret = 1;
  for (; pw; pw >>= 1, b = b * b % mod)
    if (pw & 1) ret = ret * b % mod;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i < N; i++) {
    sum[i] = (1LL * i * cnt[i]) % mod;
    sum2[i] = (1LL * sum[i] * i) % mod;
    long long pas = 1LL * cnt[i] * (cnt[i]-1)/2;
    pas %= mod;
    sumd[i] = (pas * i % mod) * i % mod;
  }
  int mul = 1;
  for (int k = 0; k < 6; k++) {
    for (int i = N-1; i >= 0; i--) {
      int d = (i/mul) % 10;
      for (int j = d+1; j <= min(d+1, 9); j++) {
        int o = i+(j-d)*mul;
        sumd[i] = (sumd[i] + sumd[o] + 1LL * sum[i] * sum[o]) % mod;
        sum[i] = (sum[i] + sum[o]) % mod;
        sum2[i] = (sum2[i] + sum2[o]) % mod;
        cnt[i] += cnt[o];
      }
    }
    mul *= 10;
  }
  for (int i = 0; i < N; i++) {
    dp[i] = 0;
    if (cnt[i] >= 1)
      dp[i] = (dp[i] + 1LL * sum2[i] * powmod(2, cnt[i]-1)) % mod;
    if (cnt[i] >= 2)
      dp[i] = (dp[i] + 2LL * sumd[i] * powmod(2, cnt[i]-2)) % mod;
  }
  mul = 1;
  for (int k = 0; k < 6; k++) {
    for (int i = 0; i < N; i++) {
      int d = (i/mul) % 10;
      for (int j = d+1; j <= min(d+1, 9); j++) {
        int o = i+(j-d)*mul;
        if ((j-d) & 1)
          dp[i] -= dp[o], sum[i] -= sum[o];
        else
          dp[i] += dp[o], sum[i] += sum[o];
        if (dp[i] < 0) dp[i] += mod;
        if (dp[i] >= mod) dp[i] -= mod;
      }
    }
    mul *= 10;
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    dp[i] %= mod;
    if (dp[i] < 0) dp[i] += mod;
    ans ^= 1LL * i * dp[i];
  }
  cout << ans << endl;
  return 0;
}