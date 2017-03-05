#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long pw) {
  long long ret = 1;
  for (; pw; pw >>= 1, b = (b * b) % mod)
    if (pw & 1) ret = (ret * b) % mod;
  return ret;
}

long long get(long long r, long long c) {
  if (r > c)
    swap(r, c);
  long long inv2 = powmod(2, mod -2), inv6 = powmod(6, mod-2);
  long long x = ((r-1) * r) % mod, x2 = (x * x) % mod;
  long long ans = (inv2 * x2 - x + x * (r+1)) % mod;
  x = (x * (r+1)) % mod;
  ans = (ans + (c-r) * x) % mod;
  ans = (ans * inv6) % mod;
  if (ans < 0) ans += mod;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int r, c;
    scanf("%d %d", &r, &c);
    printf("Case #%d: %lld\n", tc, get(r, c));
  }
  return 0;
}