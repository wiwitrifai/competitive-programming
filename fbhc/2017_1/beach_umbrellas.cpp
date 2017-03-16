#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 5e6 + 10;

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}

long long v[N], iv[N], fac[N], ifac[N];
int r[N], n;
long long m;

long long C(long long up, long long down) {
  long long ret = (v[m-up+down-1] * iv[m-up-1]) % mod;
  ret = (ret * ifac[down]) % mod;
  assert( m-up-1 >= 0 && m-up+down-1 < N);
  // cerr << up << " " << down << " " << ret << endl;
  return ret; 
} 

int main() {
  time_t start_t = clock();
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    ifac[i] = powmod(fac[i], mod-2);
  }
  cerr << "Precompute done!" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%d %lld", &n, &m);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", r+i);
      sum += r[i];
    }
    long long dsum = sum * 2;
    long long mi = m;
    if (mi >= N)
      mi = N;
    long long now = 1;
    for (int i = 0; i < mi; i++) {
      now = (now * (m-i)) % mod;
      v[i] = now;
      iv[i] = powmod(v[i], mod-2);
    }
    long long ans = 0;
    long long mul = (fac[n-2] * 2) % mod;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        long long cur = dsum - r[i] - r[j] - (n-1);
        long long sisa = m - cur;
        // cerr << sisa << endl;
        if (sisa < n)
          continue;
        ans += (C(sisa, n) * mul) % mod;
        if (ans >= mod)
          ans -= mod;
      }
    }
    if (n == 1)
      ans = m % mod;
    printf("Case #%d: %lld\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}