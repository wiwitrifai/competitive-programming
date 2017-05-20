#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long fac[N], inv[N];
long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1) r = r * b % m;
  return r;
}
int m, euler;
vector< int > vp;
vector< int > mul;
map< long long, long long > mfac, minv;

void cfac(long long n) {
  if (mfac.count(n)) return;
  long long ret = powmod(fac[m-1], n/m, m) * fac[n % m] % m;
  for (auto it : mul) {
    if (it == -1) continue;
    cfac(n / abs(it));
    if (it < 0)
      ret = ret * minv[n / abs(it)] % m;
    else
      ret = ret * mfac[n / abs(it)] % m;
  }
  mfac[n] = ret;
  minv[n] = powmod(ret, euler-1, m);
}
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld %d", &n, &k, &m);
    long long mi = (n + k - 1)/k;
    long long up = mi * k - n + mi - 1, down = mi-1, cnt = 0;
    euler = m;
    long long now = m;
    vp.clear();
    mul.clear();
    mul.push_back(-1);
    for (int i = 2; i <= now; i++) if ((now % i) == 0) {
      vp.push_back(i);
      euler -= euler/i;
      now /= i;
      while ((now % i) == 0) now /= i;
      int nmul = mul.size();
      for (int j = 0; j < nmul; j++)
        mul.push_back(mul[j] * -i);
    }
    assert(now == 1);
    fac[0] = inv[0] = 1;
    for (int i = 1; i < m; i++) {
      now = gcd(i, m) == 1 ? i : 1;
      fac[i] = 1LL * fac[i-1] * now % m;
    }
    mfac.clear();
    minv.clear();
    mfac[0] = minv[0] = 1;
    cfac(up);
    cfac(down);
    cfac(up-down);
    cnt = 1LL * minv[down] * minv[up-down] % m;
    cnt = 1LL * mfac[up] * cnt % m;
    for (int p : vp) {
      long long cur = up, x = 0;
      while (cur) cur /= p, x += cur;
      cur = down;
      while (cur) cur /= p, x -= cur;
      cur = up - down;
      while (cur) cur /= p, x -= cur;
      assert(x >= 0);
      cnt = (cnt * powmod(p, x, m)) % m;
    }
    printf("%lld %lld\n", mi, cnt);
  }
  return 0;
} 