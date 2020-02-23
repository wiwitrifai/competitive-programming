#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int ans[N];

int main() {
  int m, k;
  scanf("%d %d", &m, &k);
  ans[0] = 1;
  for (int i = 1; i <= k; ++i) {
    ans[i] = powmod(i * 2 + 1, m) - powmod(i * 2 - 1, m);
    if (ans[i] < 0)
      ans[i] += mod;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = i+i; j <= k; j += i) {
      ans[j] -= ans[i];
      if (ans[j] < 0)
        ans[j] += mod;
    }
  }
  int tot = 0;
  for (int i = 0; i <= k; ++i) {
    tot += ans[i];
    if (tot >= mod)
      tot -= mod;
  }
  tot %= mod;
  if (tot < 0)
    tot += mod;
  printf("%d\n", tot);
  return 0;
}
