// TLE during testing, maybe TL was too strict?

#include <bits/stdc++.h>

using namespace std;

struct NTT {
public:
  NTT(const int _mod) : mod(_mod) {
    proot = find_primitive_root();
    int totient = mod-1;
    max_len = 1;
    while ((totient & max_len) == 0)
      max_len <<= 1;
  }

  void fft(vector<int> & a, bool invert) {
    int n = (int) a.size();
    if (n & (n-1)) {
      int pw = 1;
      while (pw < n) pw <<= 1;
      n = pw;
      a.resize(n, 0);
      assert(false);
    }
    assert(n <= max_len);

    for (int i=1, j=0; i<n; ++i) {
      int bit = n >> 1;
      for (; j>=bit; bit>>=1)
        j -= bit;
      j += bit;
      if (i < j)
        swap (a[i], a[j]);
    }

    int root = powmod(proot, (mod-1) / n);
    if (invert)
      root = inverse(root);

    for (int len = 2; len <= n; len <<= 1) {
      int wlen = root;
      for (int i = len; i < n; i <<= 1)
        wlen = int (wlen * 1ll * wlen % mod);
      for (int i = 0; i < n; i += len) {
        int w = 1;
        for (int j = 0; j < len/2; ++j) {
          int u = a[i+j], v = int (a[i+j+len/2] * 1ll * w % mod);
          a[i+j] = u+v < mod ? u+v : u+v-mod;
          a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
          w = int (w * 1ll * wlen % mod);
        }
      }
    }
    if (invert) {
      int nrev = inverse(n);
      for (int i = 0; i < n; ++i)
        a[i] = int (a[i] * 1ll * nrev % mod);
    }
  }

  vector<int> multiply(vector<int> a, vector<int> b) {
    int len = a.size() + b.size() - 1;
    int pw = 1;
    while (pw < len) pw <<= 1;
    len = pw;
    a.resize(len, 0);
    b.resize(len, 0);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < len; ++i)
      a[i] = 1LL * a[i] * b[i] % mod;
    fft(a, true);
    while (len > 0 && a[len-1] == 0)
      --len;
    a.resize(len);
    return a;
  }
  long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
      if (p & 1)
        r = r * b % mod;
    return r;
  }

  long long inverse(int x) {
    return powmod(x, mod-2);
  }

private:
  const int mod;
  int proot;
  int max_len = 1;

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
};

const int mod = 998244353;

NTT ntt(mod);

void normalize(vector<int> & ret, int n) {
  for (int i = (int)ret.size(); i >= n; --i) {
    ret[i-n] += ret[i];
    ret[i] = 0;
    if (ret[i-n] >= mod)
      ret[i-n] -= mod;
  }
}

vector<int> pow(vector<int> b, long long e) {
  int n = b.size();
  int len = b.size() + b.size() - 1;
  int pw = 1;
  while (pw < len) pw <<= 1;
  len = pw;
  b.resize(len, 0);
  vector<int> r(pw, 0);
  r[0] = 1;
  for (; e; e >>= 1) {
    ntt.fft(b, false);
    if (e & 1) {
      ntt.fft(r, false);
      for (int i = 0; i < len; ++i) {
        r[i] = (long long)r[i] * b[i] % mod;
      }
      ntt.fft(r, true);
      normalize(r, n);
    }
    for (int i = 0; i < len; ++i) {
      b[i] = (long long)b[i] * b[i] % mod;
    }
    ntt.fft(b, true);
    normalize(b, n);
  }
  return r;
}

int main() {
  int n, m;
  long long r;
  scanf("%d %d %lld", &n, &m, &r);
  vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x % n];
  }
  vector<int> ans = pow(cnt, r);
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
  return 0;
}
