#include <bits/stdc++.h>

using namespace std;

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

long long largemul(long long a, long long b, long long n) { // (a * b) mod n
    // assert(0 <= a && a < n && 0 <= b && b <= n);
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

long long fastexp(long long a, long long b, long long n) { // compute (a ^ b) mod n
    long long ret = 1;
    for (; b; b >>= 1, a = largemul(a, a, n))
        if (b & 1) ret = largemul(ret, a, n);
    return ret;
}

bool mrtest(long long n) { // miller rabin big primality test
    if(n == 1) return false;
    long long d = n-1;
    long long s = 0;
    while(d % 2 == 0) {
        s++;
        d /= 2;
    }
    for (long long j=0; j<(long long)A.size(); j++) {
        if (A[j] > n-1) continue;
        long long ad = fastexp(A[j], d, n);
        if (ad % n == 1) continue;
        bool notcomp = false;
        for (long long r=0; r<=max(0LL,s-1); r++) {
           long long rr = fastexp(2,r,n);
           long long ard = fastexp(ad, rr, n);        
           if(ard % n == n-1) {notcomp = true; break;}
        }
        if (!notcomp) {
           return false;
        }
    }
    return true;
}

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

long long pollard_rho(long long n) { // Pollard;s rho integer factoring
    int i = 0, k = 2;
    long long x = 3, y = 3; // random seed = 3, other values possible
    while (1) {
        i++;
        x = largemul(x, x, n)-1; // generating function
        if (x < 0) x += n;
        long long d = gcd(llabs(y - x), n); // the key insight
        if (d != 1 && d != n) return d;
        if (i == k) y = x, k *= 2;
    }
}

long long calc(long long a) {
  long long ret = 1;
  for (long long p = 2; p * p * p <= a; ++p) {
    if (a % p) continue;
    int cnt = 1;
    while ((a % p) == 0) {
      ++cnt;
      a /= p;
    }
    ret *= cnt;
  }
  if (a > 1) {
    if (mrtest(a))
      ret *= 2;
    else {
      long long s = sqrt(a);
      while (s * s < a) ++s;
      while (s * s > a) --s;
      if (s * s == a)
        ret *= 3;
      else
        ret *= 4;
    }
  }
  return ret;
}

int main() {
  long long a;
  scanf("%lld", &a);
  if (a == 0 || a == 1) {
    puts("-1");
    return 0;
  }
  cout << 2 * calc(abs(a)) * calc(abs(a-1)) << endl;
  return 0;
}
