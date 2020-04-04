#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int n;
long long a[N], dp[N], sum[N];

int main() {
  long long x, y;
  scanf("%d %lld %lld", &n, &x, &y);
  if (x > y)
    swap(x, y);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sort(a, a+n);
  for (int i = 0; i + 2 < n; ++i) {
    if (a[i+2] - a[i] < x) {
      puts("0");
      return 0;
    }
  }
  dp[0] = 1;
  sum[0] = 1;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    long long pre = a[i] - y;
    int pos = upper_bound(a, a+n, pre) - a;
    if (pos >= last)
      dp[i+1] = sum[pos] - (last < 0 ? 0 : sum[last]);
    sum[i+1] = (sum[i] + dp[i+1]) % mod;
    if (i > 0 && a[i] - a[i-1] < x) {
      last = i-1;
    }
  }
  long long ans = 0;
  bool ok = 1;
  for (int i = n-1; i >= 0; --i) {
    ans = (ans + dp[i+1]) % mod;
    if (i < n-1 && a[i+1] - a[i] < x) {
      ok = 0;
      break;
    }
  }
  if (ok)
    ans = (ans + dp[0]) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
