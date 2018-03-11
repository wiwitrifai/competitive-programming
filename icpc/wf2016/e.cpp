// by wiwit
#include <bits/stdc++.h>

using namespace std;

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
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

const int N = 2e6 + 6;

int nfac;
long long fac[N];

void add(long long p, int last) {
  for (int i = 0; i < last; ++i)
    fac[nfac++] = fac[i] * p;
}

long long convert(long long y, long long b) {
  long long ret = 0, def = y, mul = 1;
  while (y) {
    long long r = y % b;
    y /= b;
    if (r >= 10) return -1;
    ret += r * mul;
    mul *= 10;
  }
  return ret;
}

int main() {
  long long y, l;
  scanf("%lld %lld", &y, &l);
  set<long long > bases;
  for (int i = 0; i < 10; ++i) {
    long long now = y-i;
    if (now <= 10) continue;
    nfac = 1;
    fac[0] = 1;
    for (long long j = 2; j * j * j <= now; ++j) {
      if (now % j) continue;
      int last = nfac;
      long long pp = j;
      while ((now % j) == 0) {
        now /= j;
        add(pp, last);
        pp *= j;
      }
    }
    if (now > 1) {
      if (mrtest(now)) {
        add(now, nfac);
      }
      else {
        long long p = pollard_rho(now);
        long long q = now / p;
        add(p, nfac);
        add(q, nfac);
      }
    }
    //cerr << y-i << " : ";
    for (int j = 0; j < nfac; ++j) {
  //    cerr << fac[j] << " ";
      if (fac[j] > 10)
        bases.insert(fac[j]);
    }
//    cerr << endl;
  }
  long long ans = 10;
  for (long long b : bases) {
    long long res = convert(y, b);
    if (res >= l)
      ans = max(ans, b);
  }
  printf("%lld\n", ans);
  return 0;
}