#include <bits/stdc++.h>

using namespace std;

const int N = 2, mod = 1e9 + 7;
struct matrix {
  long long a[2][2];
  matrix() {
    a[0][0] = a[1][1] = 1;
    a[0][1] = a[1][0] = 0;
  }
  long long * operator[](int id) {
    return a[id];
  }
  matrix operator* (matrix m) {
    matrix ret;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        long long & now = ret[i][j];
        now = 0;
        for (int k = 0; k < N; k++)
          now  = (now + 1LL * a[i][k] * m[k][j]) % mod;
      }
    }
    return ret;
  }
  matrix operator ^ (long long pw) {
    matrix ret = matrix();
    matrix base = *this;
    while (pw) {
      if (pw & 1)
        ret = ret * base;
      base = base * base;
      pw >>= 1;
    }
    return ret;
  }
  matrix operator + (matrix m) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        a[i][j] = (a[i][j] + m[i][j]) % mod;
    return * this;
  }
};

int main() {
  int q;
  matrix fib;
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;
  scanf("%d", &q);
  while (q--) {
    long long ans = 0;
    int n;
    scanf("%d", &n);
    matrix now;
    now[0][0] = now[0][1] = now[1][0] = now[1][1] = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      now = now + fib;
      now = now * (fib ^ a);
      ans = (ans + now[1][1]) % mod;
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}