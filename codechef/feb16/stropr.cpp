#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, x;
long long m, a[N];

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d%lld", &n, &x, &m);
    x--;
    for(int i = 0; i<n; i++) {
      scanf("%lld", a+i);
      a[i] %= mod;
    }
    long long ans = 0, comb;
    comb = 1;
    ans = a[x] % mod;
    m %= mod;
    for(int i = 1; i<=x; i++) {
      comb = (comb * (m-1+i)) % mod;
      comb = (comb * powmod(i, mod-2)) % mod;
      ans = (ans + (comb*a[x-i]) % mod) % mod;
    }
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}