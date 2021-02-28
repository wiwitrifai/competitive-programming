#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long extended_euclid(long long &x, long long a, long long &y, long long b) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long tx, ty;
  long long d = extended_euclid(tx, b % a, ty, a);
  y = tx;
  x = ty - (b / a) * tx;
  return d;
}

long long inverse(long long b, long long mod) {
  long long x, y;
  long long d = extended_euclid(x, b, y, mod);
  assert(d == 1);
  x %= mod;
  if (x < 0)
    x += mod;
  return x;
}

long long coprime_crt(long long r1, long long m1, long long r2, long long m2) {
  long long mod = m1 * m2;
  return (r1 * m2 * inverse(m2, m1) + r2 * m1 * inverse(m1, m2)) % mod;
}

vector<int> fprime;

long long crt(long long r1, long long m1, long long r2, long long m2) {
  long long d = gcd(m1, m2);
  if ((r1-r2) % d) return -1;
  while (d > 1) {
    int p = fprime[d];
    while ((d % p) == 0) d /= p;
    long long pm1 = 1, pm2 = 1;
    while ((m1 % p) == 0) {
      m1 /= p;
      pm1 *= p;
    }
    while ((m2 % p) == 0) {
      m2 /= p;
      pm2 *= p;
    }
    if (pm1 > pm2)
      m1 *= pm1;
    else
      m2 *= pm2;
  }
  r1 %= m1;
  r2 %= m2;
  return coprime_crt(r1, m1, r2, m2);
}

void solve() {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  int ans = 0;
  long long farthest = -1;
  long long d = gcd(n, m);
  long long maxi = 1LL * (n / d) * m;
  for (int i = 0; i < 4; ++i) {
    int posx = x-1, posy = y-1;
    int parity_x = i & 1, parity_y = (i >> 1) & 1;
    if (parity_x)
      posx = n-1-posx;
    if (parity_y)
      posy = m-1-posy;
    long long z = crt(posx, n, posy, m);
    if (z < 0)
      continue;
    long long krow = z/n, kcol = z/m;
    if (((krow & 1) != parity_x) || ((kcol & 1) != parity_y) || z >= maxi) continue;
    if (farthest < z) {
      farthest = z;
      ans = ((krow + kcol) % 9) + 1;
    }
  }
  printf("%d\n", ans);
}

int main() {
  fprime.resize(int(1e6 + 6), -1);
  for (int i = 2; i < (int)fprime.size(); ++i) {
    if (fprime[i] != -1) continue;
    for (int j = i; j < (int)fprime.size(); j += i)
      fprime[j] = i;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    solve();
  }
  return 0;
}
