#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 163577857;
 
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
 
void fft (vector<int> & a, bool invert, int root, int root_1, int root_pw) {
  a.resize(root_pw);
  int n = root_pw;
 
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
 
  for (int len=2; len<=n; len<<=1) {
    int wlen = invert ? root_1 : root;
    for (int i=len; i<root_pw; i<<=1)
      wlen = int (wlen * 1ll * wlen % mod);
    for (int i=0; i<n; i+=len) {
      int w = 1;
      for (int j=0; j<len/2; ++j) {
        int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
        a[i+j] = u+v < mod ? u+v : u+v-mod;
        a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
        w = int (w * 1ll * wlen % mod);
      }
    }
  }
  if (invert) {
    int nrev = powmod(n, mod-2);
    for (int i=0; i<n; ++i)
      a[i] = int (a[i] * 1ll * nrev % mod);
  }
}
 
 
bool cek_root(int r, int root_pw) {
  int cur = 1;
  for (int j = 1; j < root_pw; ++j) {
    cur = (1LL * cur * r) % mod;
    if (cur == 1) {
      return 0;
    }
  }
  cur = (1LL * cur * r) % mod;
  return cur == 1;
}
int find_root(int root_pw) {
  for (int r = 1; ; ++r) {
    if (cek_root(r, root_pw)) {
      return r;
    }
  }
}
 
const int N = 1 << 20, LG = 21;
 
int root[LG], root_1[LG];
 
vector<int> mulpoli(int l, int r) {
  if (l == r) {
    return {1, l};
  }
  int mid = (l + r) >> 1;
  vector<int> pl = mulpoli(l, mid), pr = mulpoli(mid+1, r);
  int size = r-l+2;
  int lg = 31 - __builtin_clz(size);
  if (size & (size-1)) ++lg;
  size = 1 << lg;
  fft(pl, 0, root[lg], root_1[lg], size);
  fft(pr, 0, root[lg], root_1[lg], size);
  for (int i = 0; i < size; ++i)
    pl[i] = (1LL * pl[i] * pr[i]) % mod;
  fft(pl, 1, root[lg], root_1[lg], size);
  return pl;
}
 
long long fac[N], inv[N];
 
long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}
 
int main() {
  int r = 97; // find_root(1 << 20);
  for (int i = 20; i >= 0; --i) {
    root[i] = r;
    root_1[i] = powmod(r, mod-2);
    // assert(cek_root(r, 1 << i));
    r = 1LL * r * r % mod;
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 1) {
      puts("1");
      continue;
    }
    vector<int> f = mulpoli(2, n);
    long long ans = 0;
    for (int i = 0; i <= k; ++i) {
      ans = (ans + f[i] * C(k, i)) % mod;
    }
    cout << ans << endl;
  }
  return 0;
} 