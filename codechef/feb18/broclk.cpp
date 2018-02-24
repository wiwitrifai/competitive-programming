#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b*b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct matrix {
  long long a[2][2];
  matrix() {
    memset(a, 0, sizeof a);
  }
  void identity() {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) 
        a[i][j] = (i == j);
  }
  matrix operator*(matrix m) {
    matrix res;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        res.a[i][j] = (a[i][0] * m.a[0][j] + a[i][1] * m.a[1][j]) % mod;
    return res;
  }
  matrix operator^(long long p) {
    matrix r; r.identity();
    matrix b = *this;
    for (; p; p >>= 1, b = b * b)
      if (p & 1)
        r = r * b;
    return r;
  }
};

int main() {
  assert(((mod + 1) % 4) == 0);
  int t;
  scanf("%d", &t);
  while (t--) {
    long long d, l, tim;
    scanf("%lld %lld %lld", &l, &d, &tim);
    long long c = d * powmod(l, mod - 2) % mod;
    matrix m;
    m.a[0][0] = c;
    m.a[0][1] = (c * c - 1) % mod;
    m.a[1][0] = 1;
    m.a[1][1] = c;
    matrix a;
    a.a[0][0] = 1;
    a.a[1][0] = 0;
    matrix res = (m ^ tim) * a;
    long long ans = l * res.a[0][0] % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}