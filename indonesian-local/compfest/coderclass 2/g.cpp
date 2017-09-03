/*
  problem : Jajar Genjang Pascal
  link    : http://judgels-competition.cs.ui.ac.id/contests/6/problems/107/
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int mod = 1e9 + 9;

long long fac[N], inv[N];

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw ) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}

long long C(int n, int k) {
  if(n < k || k < 0)
    return 0;
  return (((fac[n] * inv[n-k]) % mod) * inv[k]) % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b, l, r;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    int ya = a-1, xa = b-1, yb = ya + l-1 + r-1, xb = xa + r-1;
    // cerr << ya << " " << xa << " " << yb << " " << xb << endl;
    long long ans = C(yb + 2, xb + 1) - C(ya + l-2 + 2, xa-1 + 1) - C(ya + r-2 + 2, xa+ r - 1 + 1) + C(ya-2 + 2, xa-1 + 1);
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }

  return 0;
}