#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
long long fac[N], ifac[N];

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

long long C(long long a, long long b) {
  if(a < b)
    return 0;
  return (((fac[a] * ifac[b]) % mod) * ifac[a-b]) % mod;
} 
int main() {
  fac[0] = ifac[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1]*i) % mod;
    ifac[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    n--; m--; x--; y--;
    long long ans = C(n+m, m) - C(x+y, y) * C(n-x+m-y, m-y);
    ans %= mod;
    if(ans < 0)
      ans += mod;
    cout << ans << endl;
  }
  return 0;
}