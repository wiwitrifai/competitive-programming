#include <bits/stdc++.h>

using namespace std;

const int mod = 200003;


long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int find_primitive_root() {
  int totient = mod - 1;
  vector<int> checks;
  int tmp = totient;
  for (int p = 2; p * p <= tmp; ++p) {
    if (tmp % p) continue;
    checks.push_back(totient/p);
    while ((tmp % p) == 0) tmp /= p;
  }
  if (tmp > 1)
    checks.push_back(totient/tmp);
  for (int r = 2; ; ++r) {
    bool ok = 1;
    for (int f : checks) {
      if (powmod(r, f) == 1) {
        ok = 0;
        break;
      }
    }
    if (ok)
      return r;
  }
  assert(false);
}

int pw[mod], pp[mod];

/***************** FFT dengan complex ******************/
typedef complex<double> cd;
typedef vector< cd > vcd;

// asumsi ukuran as = 2^k, dengan k bilangan bulat positif
vcd fft(const vcd &as) {
  int n = (int)as.size();
  int k = 0;
  while((1<<k) < n) k++;
  vector< int > r(n);
  r[0] = 0;
  int h = -1;
  for(int i = 1; i<n; i++) {
    if((i & (i-1)) == 0)
      h++;
    r[i] = r[i ^ (1 << h)];
    r[i] |= (1<<(k-h-1));
  }
  vcd root(n);
  for(int i = 0; i<n; i++) {
    double ang = 2.0*M_PI*i/n;
    root[i] = cd(cos(ang), sin(ang));
  }

  vcd cur(n);
  for(int i = 0; i<n; i++)
    cur[i] = as[r[i]];

  for(int len = 1; len < n; len <<= 1 ) {
    vcd ncur(n);
    int step = n/(len << 1);
    for(int pdest = 0; pdest <n;) {
      for(int i = 0; i<len; i++) {
        cd val = root[i*step]*cur[pdest + len];
        ncur[pdest] = cur[pdest] + val;
        ncur[pdest + len] = cur[pdest] - val;
        pdest++;
      }
      pdest += len;
    }
    cur.swap(ncur);
  }
  return cur;
}

vcd inv_fft(const vcd& fa) {
  int nn = fa.size();
  vcd res = fft(fa);
  for(int i = 0; i<nn; i++) {
    res[i] /= nn;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

int main() {
  int root = find_primitive_root();
  for (int i = 0, cur = 1; i < mod - 1; ++i) {
    pp[i] = cur;
    pw[cur] = i;
    cur = cur * root % mod;
  }
  int sz = mod + mod;
  while ((sz - 1) & sz) ++sz;
  vector<int> cnt(sz, 0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == 0) continue;
    x = pw[x];
    ++cnt[x];
  }
  vcd f(cnt.size());
  for (int i = 0; i < (int)cnt.size(); ++i)
    f[i] = cd(cnt[i], 0);
  f = fft(f);
  for (int i = 0; i < (int)f.size(); ++i) {
    f[i] *= f[i];
  }
  f = inv_fft(f);
  vector<long long> fcnt(f.size());
  for (int i = 0; i < (int)f.size(); ++i) {
    fcnt[i] = (long long)floor(f[i].real() + 0.5);
  }
  for (int i = 0; i < mod; ++i) {
    fcnt[i * 2] -= cnt[i];
  }
  long long ans = 0;
  for (int i = 0, z = 0; i < (int)fcnt.size(); ++i, ++z) {
    if (z >= mod-1)
      z -= mod - 1;
    ans += (long long)pp[z] * fcnt[i];
  }
  ans /= 2;
  printf("%lld\n", ans);
  return 0;
}
