#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 6;

long long powmod(long long b, long long p) {
  if (p < 0) return 0;
  long long ret = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) ret = ret * b % mod;
  return ret;
}
long long fac[N], inv[N];
long long C(int n, int k) {
  if (k > n || k < 0 || n < 0) return 0;
  return ((fac[n] * inv[k]) % mod) * inv[n-k] % mod;
}
char s[5];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int m, n, k, p;
  scanf("%d %d %d %s", &m, &n, &k, s);
  p = (s[0]-'0') * 1000 +(s[2]-'0') * 100 + (s[3]-'0') * 10 + (s[4]-'0') * 1;
  p = (1LL * p * powmod(1000, mod-2)) % mod;
  int ip = (1-p) % mod;
  if (ip < 0) ip += mod;
  long long ans = C(n-1, k-1) * powmod(p, k) % mod;
  ans = ans * powmod(ip, n-k) % mod;
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}