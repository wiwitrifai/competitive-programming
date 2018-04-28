#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p){
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = fac[i-1] * i % mod;
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * (i+1) % mod;
    assert((inv[i] * fac[i] % mod) == 1);
  }
  int n;
  scanf("%d", &n);
  --n;
  long long ans = fac[n] * n % mod;
  for (int i = 1; i <= n; ++i) {
    int sela = i+1;
    int ada = n - sela;
    long long cur = C(ada, i) * fac[n-i] % mod;
    cur = (cur * fac[i]) % mod;
    ans = (ans + mod - cur) % mod;
  } 
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}