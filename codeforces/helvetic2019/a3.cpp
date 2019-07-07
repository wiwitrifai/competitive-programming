// TLE
#include <bits/stdc++.h>

using namespace std;

struct NTT {
  int mod = 7340033;
  int root = 5;
  int root_1 = 4404020; // root ^ (-1) % mod
  int root_pw = 1<<20;
  NTT(int _mod) : mod(_mod) {
    int val = mod - 1;
    root_pw = 1;
    while ((root_pw & val) == 0 && root_pw <= int(1e5)) root_pw <<= 1;

    root = 2;
    while (1) {
      bool ok = powmod(root, (mod-1)/2) != 1;
      if (ok) break;
      ++root;
    }
    root = powmod(root, (mod - 1) / root_pw);
    root_1 = powmod(root, mod-2);
  }

  long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
      if (p & 1)
        r = r * b % mod;
    return r;
  }

  void fft (vector<int> & a, bool invert = false) {
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
  }
};

const int N = 1e6 + 6;

char s[N], t[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s %s", s, t);
  vector<int> diff(n);
  for (int i = 0; i < n; ++i)
    diff[i] = (int)s[i] - (int)t[i];
  int pw2 = 1;
  while (pw2 <= max(m, n)) {
    pw2 <<= 1;
  }
  for (int mod = pw2 + 1; ; mod += pw2) {
    bool is_prime = 1;
    for (int i = 2; 1LL * i * i <= mod; ++i) {
      if (mod % i) continue;
      is_prime = 0;
      break;
    }
    if (!is_prime) continue;
    NTT cur(mod);
    vector<int> now(cur.root_pw, 0);
    for (int i = 0; i < n; ++i) {
      now[i] = diff[i] % cur.mod;
      if (now[i] < 0)
        now[i] += cur.mod;
    }
    cur.fft(now);
    long long b = 1;
    for (int i = 0; i < now.size(); ++i) {
      if (now[i] == 0) {
        if (b > 1 && b < cur.mod-1) {
          long long sum = 0, bb = 1;
          for (int i = 0; i < n; ++i) {
            sum = (sum + bb * diff[i]) % mod;
            bb = bb * b % mod;
          }
          assert(sum == 0);
          cout << mod << " " << b << endl;
          return 0;
        }
      }
      b = 1LL * b * cur.root % cur.mod;
    }
  }
  return 0;
}
