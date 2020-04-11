#include <bits/stdc++.h>

using namespace std;


/**
 *  Primality and Factoring
 *
 *  Usage:
 *    mrtest(n) = miller-rabbin test for checking primality of a number.
 *    pollard_tho(n) = for factoring a number (make sure it's not prime)
 */

struct Primality {
  vector<long long> A = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  // if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

  long long largemul(long long a, long long b, long long n) {
    // assert(0 <= a && a < n && 0 <= b && b < n);
    long long r = 0;
    for (; b; b >>= 1, a <<= 1) {
      if (a >= n) a -= n;
      if (b & 1) {
        r += a;
        if (r >= n) r -= n;
      }
    }
    return r;
  }

  long long fastexp(long long a, long long b, long long n) {
    // assert(0 <= a && a < n && b >= 0);
    long long ret = 1;
    for (; b; b >>= 1, a = largemul(a, a, n))
      if (b & 1) ret = largemul(ret, a, n);
    return ret;
  }

  bool mrtest(long long n) {
    if (n == 1) return false;
    long long d = n-1;
    int s = 0;
    while ((d & 1) == 0) {
      s++;
      d >>= 1;
    }
    s--;
    if (s < 0) s = 0;
    for (int j = 0; j < (int)A.size(); j++) {
      if (A[j] >= n) continue;
      long long ad = fastexp(A[j], d, n);
      if (ad == 1) continue;
      bool notcomp = false;
      long long a2rd = ad;
      for (int r = 0; r <= s; r++) {
       if(a2rd == n-1) {notcomp = true; break;}
       a2rd = largemul(a2rd, a2rd, n);
      }
      if (!notcomp) {
       return false;
      }
    }
    return true;
  }

  long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

  long long pollard_rho(long long n) {
    int i = 0, k = 2;
    long long x = 3, y = 3; // random seed = 3, other values possible
    while (1) {
      i++;
      x = largemul(x, x, n)-1; // generating function
      if (x < 0) x += n;
      long long d = gcd(llabs(y - x), n); // the key insight
      if (d != 1 && d != n) return d;
      if (i == k) y = x, k <<= 1;
    }
  }
};

const int N = 1e6 + 6, S = 505, mod = 998244353;

long long C[S][S];

int main() {
  for (int i = 0; i < S; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  Primality np;
  long long d;
  scanf("%lld", &d);
  vector<long long> primes;
  for (int x = 2; x < N; ++x) {
    if (d % x) continue;
    while ((d % x) == 0) {
      d /= x;
    }
    primes.push_back(x);
  }
  if (d > 1) {
    if (np.mrtest(d)) {
      primes.push_back(d);
    }
    else {
      long long x = np.pollard_rho(d);
      long long y = d / y;
      primes.push_back(x);
      if (y != x)
        primes.push_back(y);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    long long g = np.gcd(u, v);
    u /= g;
    v /= g;
    int lu = 0, lv = 0;
    long long ans = 1;
    for (long long p : primes) {
      int cu = 0, cv = 0;
      while ((u % p) == 0) {
        ++cu;
        u /= p;
      }
      while ((v % p) == 0) {
        ++cv;
        v /= p;
      }
      if (cu > 0)
        ans = ans * C[lu+cu][cu] % mod;
      if (cv > 0)
        ans = ans * C[lv+cv][cv] % mod;
      lu += cu;
      lv += cv;
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
