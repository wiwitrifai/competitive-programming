#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 5e5 + 5;

long long inv[N];

long long powmod(long long b, long long p) {
  long long ret = 1;
  while(p) {
    if(p&1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  for(int i = 1; i<N; i++)
    inv[i] = powmod(i, mod-2);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &m, &n);
    long long mul = powmod(n, m-n), in = (inv[n] * (n-1)) % mod, ans = mul;
    for(int i = 0; i<m-n; i++) {
      mul = (mul * (n+i)) % mod;
      mul = (mul * inv[i+1]) % mod;
      mul = (mul * in) % mod;
      ans = (ans + mul) % mod;
    }
    printf("%lld\n", ans);
  }

  return 0;
}