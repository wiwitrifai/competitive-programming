#include <bits/stdc++.h>

using namespace std;

const int mod = 924844033;

long long powmod(long long b, long long pw) {
  long long ret = 1;
  for (; pw; pw>>=1, b = (b * b) % mod)
    if (pw&1) ret = (ret * b) % mod;
  return ret;
}

const long long root = powmod(5, 441);
const long long root_1 = powmod(root, mod-2);
const int root_pw = 1<<21;

 
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
    int nrev = powmod (n, mod-2);
    for (int i=0; i<n; ++i)
      a[i] = int (a[i] * 1ll * nrev % mod);
  }
}

int main() {
  vector< int > fac(root_pw);
  fac[0] = 1;
  for (int i = 1; i < root_pw; i++) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
  }
  scanf("%d", &n);
  vector< int > v;
  fft(fac, 0);
  long long cur = 1;
  for (int i = 0; i < root_pw; i++) {
    fac[i] = powmod(fac[i], mod-2);
  }
  fft(fac, 1);
  int n;
  for (int i = 0; i <= n; i++) {
    int now = (mod-fac[i]) % mod;
    if (now < 0) now += mod;
    printf("%d %d\n", fac[i], now);
  }
  return 0;
}