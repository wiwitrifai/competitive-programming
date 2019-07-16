#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const int root = 646;
const int root_1 = powmod(root, mod-2); // root ^ (-1) % mod
const int root_pw = 1<<20;

 
void fft (vector<int> & a, bool invert) {
  int n = (int) a.size();
 
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

void sqrfft(vector<int> & a) {
  int len = a.size() * 2;
  int lg = 0;
  while ((1 << lg) < len) ++lg;
  len = 1 << lg;
  a.resize(len, 0);
  fft(a, false);
  for (int i = 0; i < len; ++i)
    a[i] = 1LL * a[i] * a[i] % mod;
  fft(a, true);
  while (len > 1 && a[len-1] == 0) --len;
  a.resize(len);
}

vector<int> multiply(vector<int> & a, vector<int> & b) {
  int len = a.size() + b.size();
  int lg = 0;
  while ((1 << lg) < len) ++lg;
  len = 1 << lg;
  a.resize(len, 0);
  b.resize(len, 0);
  fft(a, false);
  fft(b, false);
  vector<int> res(len);
  for (int i = 0; i < len; ++i)
    res[i] = 1LL * a[i] * b[i] % mod;
  fft(res, true);
  while (len > 1 && res[len-1] == 0) --len;
  res.resize(len);
  return res;
}

vector<int> powfft(vector<int> & a, int k) {
  // cerr << k << endl;
  if (k == 0)
    return {1};
  if (k == 1)
    return a;
  vector<int> b = a;
  vector<int> res = powfft(a, k/2);
  sqrfft(res);
  if (k & 1) {
    res = multiply(res, b);
  }
  return res;
}

int main() {
  // for (int r = 2;; ++r) {
  //   if (powmod(r, root_pw) != 1) continue;
  //   if (powmod(r, root_pw/2) == 1) continue;
  //   cerr << r << endl;
  //   for (int i = 1; i < root_pw; ++i) {
  //     assert(powmod(r, i) != 1);
  //   }
  //   return 0;
  // }
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(10, 0);
  for (int i = 0; i < k; ++i) {
    int d;
    scanf("%d", &d);
    a[d] = 1;
  }
  while (a.size() > 1 && a.back() == 0) a.pop_back();
  a = powfft(a, n/2);
  long long ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    ans = (ans + 1LL * a[i] * a[i]) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}