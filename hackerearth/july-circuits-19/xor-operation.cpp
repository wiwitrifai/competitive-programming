#include <bits/stdc++.h>

using namespace std;

const int N = 2;
const int mod = 1e9 + 7;
struct matrix {
  int n, m;
  int a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    memset(a, 0, sizeof a);
  }
  void reset() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; ++i)
      a[i][i] = 1;
  }
  const int * operator[](const int id) const {
    return a[id];
  }
  int * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i < this->n; ++i) {
      for(int j = 0; j < mat.m; ++j) {
        long long now = 0;
        for(int k = 0; k<this->m; ++k) {
          now = (now + (long long)this->a[i][k] * mat[k][j]) % mod;
        }
        ret[i][j] = now;
      }
    }
    return ret;
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

ostream& operator<<(ostream& os, const matrix & mat) {
  for(int i = 0; i < mat.n; ++i) {
    for(int j = 0; j < mat.m; ++j)
      os << mat.a[i][j] << " ";
    os << endl;
  }
  return os;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    long long ans = 0;
    for (int i = 0; i < 30; ++i) {
      int cur = n >> i;
      int one = cur / 2, zero = cur - one;
      one <<= i;
      zero <<= i;
      if (cur & 1)
        one += n + 1 - (cur << i);
      else
        zero += n + 1 - (cur << i);
      assert(one + zero == n+1);
      matrix init(2, 1);
      init[(s >> i) & 1][0] = 1;
      matrix trans(2, 2);
      int tot = powmod(n+1, mod-2);
      one = 1LL * one * tot % mod;
      zero = 1LL * zero * tot % mod;
      trans[0][0] = zero;
      trans[0][1] = one;
      trans[1][0] = one;
      trans[1][1] = zero;
      matrix result = (trans ^ k) * init;
      ans = (ans + 1LL * result[1][0] * (1LL << i)) % mod;
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
