#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 5;

long long powmod(long long b, long long p, int m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1) r = r * b % m;
  return r;
}

int cnt[N];
long long dp[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  for (int i = 1; i < N; i++) {
    for (int j = i+i; j < N; j += i)
      cnt[i] += cnt[j];
  }
  long long ans = 0;
  long long pk = powmod(2, k, mod-1);
  for (int i = N-1; i > 0; i--) {
    dp[i] = 0;
    dp[i] = powmod(cnt[i], pk, mod); 
    for (int j = i+i; j < N; j += i)
      dp[i] = (dp[i] + mod - dp[j]) % mod;
    ans = (ans + dp[i] * i) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}