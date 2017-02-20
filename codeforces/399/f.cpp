#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;
long long fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long ret= 1;
  for (; p; p >>= 1, b = (b * b) % mod)
    if (p&1) ret = (ret * b) % mod;
  return ret;
}

long long C(long long n, long long k) {
  if (k < 0 || n < k) return 0; 
  assert(n < N && k < N && n-k < N);
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}
long long H(long long n, long long k) {
  return C(n+k-1, k-1);
}
int main() {
  fac[0] = inv[0]= 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int f, w, h;
  scanf("%d %d %d", &f, &w, &h);
  h++;
  if (w == 0)
    cout << 1 << endl;
  else if (f == 0) {
    cout << (w >= h) << endl;
  }
  else {
    long long p, q;
    p = q = 0;
    for (int i = 1; i <= w; i++) {
      long long pw = H(w-1LL * i*h, i);
      long long allw = H(w-i, i);
      long long pb = (H(f-(i-1), i-1) + H(f-i, i) * 2 + H(f-(i+1), i+1)) % mod;
      p = (p + pw * pb) % mod;
      q = (q + allw * pb) % mod;
    }
    long long ans = (p * powmod(q, mod-2)) % mod;
    if (ans < 0)
      ans += mod;
    cout << ans << endl;
  }
  return 0;
}