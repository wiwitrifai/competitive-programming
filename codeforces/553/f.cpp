#include <bits/stdc++.h>

using namespace std;


const int N = 105;
const long long mod = 1e9 + 7;
struct matrix {
  int n, m;
  long long a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    memset(a, 0, sizeof a);
  }
  void reset() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; i++)
      a[i][i] = 1;
  }
  const long long * operator[](const int id) const {
    return a[id];
  }
  long long * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        long long &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->a[i][k] * mat[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++)
        cout << a[i][j] << " ";
      cout << endl;
    }
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

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int zero = 0, one;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (a[i] == 0)
      ++zero;
  }
  one = n - zero;
  if (zero == 0 || one == 0) {
    puts("1");
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < zero; ++i)
    cnt += a[i];
  matrix awal(zero+1, 1);
  awal[cnt][0] = 1;
  matrix trans(zero+1, zero+1);
  long long inv = powmod(1LL * n * (n - 1) / 2, mod - 2);
  for (int i = 0; i <= zero; ++i) {
    int lef = i, rig = one - i;
    if (rig < 0) continue;
    if (i && lef > 0 && rig < one) {
      trans[i-1][i] = 1LL * (1LL * lef * (one - rig) % mod) * inv % mod;
    }
    if (i+1 <= zero && rig > 0) {
      trans[i+1][i] = 1LL * (1LL * (zero - lef) * rig % mod) * inv % mod;
    }
    long long cnt = 1LL * lef * rig % mod;
    cnt = (cnt + 1LL * (zero - lef) * (one - rig)) % mod;
    cnt = (cnt + 1LL * zero * (zero - 1) / 2) % mod;
    cnt = (cnt + 1LL * one * (one - 1) / 2) % mod;
    trans[i][i] = 1LL * cnt * inv % mod;
  }
  matrix res = (trans ^ k) * awal;
  long long ans = res[0][0] % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
