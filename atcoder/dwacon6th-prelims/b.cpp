#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int x[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
  }
  for (int i = 0; i + 1 < n; ++i) {
    x[i] = x[i+1] - x[i];
  }
  long long fact = 1;
  --n;
  for (int i = 1; i <= n; ++i)
    fact = fact * i % mod;
  long long now = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    now = (now + fact * powmod(i+1, mod-2)) % mod;
    ans = (ans + now * x[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
