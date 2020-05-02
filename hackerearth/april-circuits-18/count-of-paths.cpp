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


const int N = 2e5 + 5, mod = 1e9 + 7, M = 2e6;

unsigned long long a[N];
long long dp[N];
long long f[N];
vector<unsigned long long> v;
vector<int> fac[N];
unsigned long long cand[M];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod) var -= mod;
}

int main() {
  int n;
  unsigned long long m;
  scanf("%d %llu", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%llu", a+i), v.push_back(a[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  vector<unsigned long long> vp;
  for (int i = 2; i < M; ++i) {
    if (m % i) continue;
    vp.push_back(i);
    while ((m % i) == 0) m /= i;
    if (m == 1) break;
  }
  if (m > 1) {
    if (mrtest(m))
      vp.push_back(m);
    else {
      unsigned long long p = pollard_rho(m), q = m / p;
      vp.push_back(p);
      if (p != q)
        vp.push_back(q);
    }
  }
  for (int i = 0; i < v.size(); ++i) {
    unsigned long long now = v[i];
    cand[0] = 1;
    int ncand = 1;
    for (unsigned long long p : vp) {
      if (now % p) continue;
      unsigned long long cur = 1;
      int last = ncand;
      while ((now % p) == 0) {
        cur *= p;
        now /= p;
        for (int j = 0; j < last; ++j)
          cand[ncand++] = cand[j] * cur;
      }
    }
    sort(cand, cand + ncand);
    for (int j = 0, id = 0; j < ncand; ++j) {
      while (v[id] < cand[j]) ++id;
      if (id >= v.size()) break;
      if (v[id] == cand[j])
        fac[i].push_back(id);
    }
  }
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
  dp[0] = 1;
  f[0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i] = 0;
    for (int d : fac[a[i]]) {
      add(dp[i], f[d]);
    }
    add(f[a[i]], dp[i]);
  }
  for (int i = 0; i < n; ++i)
    printf("%lld\n", dp[i]);
  return 0;
}