
#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

typedef int poly[N];
poly a, b, c, fib;

inline int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

void FWHT_XOR(poly P, bool inverse) { // example: xor
  for (int len = 1; 2 * len <= N; len <<= 1) {
    for (int i = 0; i < N; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        int u = P[i + j];
        int v = P[i + len + j];
        P[i + j] = add(u, v); // xor's matrix
        P[i + len + j] = add(u, mod - v);  // xor's matrix
      }
    }
  }
  if (inverse) {
    long long inv = powmod(N, mod-2);
    for (int i = 0; i < N; i++)
      P[i] = (inv * P[i]) % mod; // this for xor only
  }
}

void FWHT_AND(poly P, bool inverse) {
    for (int len = 1; 2 * len <= N; len <<= 1) {
        for (int i = 0; i < N; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = P[i + j];
                int v = P[i + len + j];
                if (!inverse) {
                    P[i + j] = v;
                    P[i + len + j] = add(u, v);
                } else {
                    P[i + j] = add(mod-u, v);
                    P[i + len + j] = u;
                }
            }
        }
    }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    ++a[s];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i;; j = (j-1) & i) {
      b[i] = (b[i] + 1LL * a[j] * a[i^j]) % mod; 
      if (j == 0) break;
    }
  }
  for (int i = 0; i < N; ++i)
    c[i] = a[i];
  FWHT_XOR(c, 0);
  for (int i = 0; i < N; ++i) {
    c[i] = 1LL * c[i] * c[i] % mod;
    if (c[i] < 0) c[i] += mod;
  }
  FWHT_XOR(c, 1);
  for (int i = 0; i < N; ++i) {
    if (i < 2)
      fib[i] = i;
    else
      fib[i] = (fib[i-1] + fib[i-2]) % mod;
    a[i] = 1LL * a[i] * fib[i] % mod;
    b[i] = 1LL * b[i] * fib[i] % mod;
    c[i] = 1LL * c[i] * fib[i] % mod;
  }
  FWHT_AND(a, 0);
  FWHT_AND(b, 0);
  FWHT_AND(c, 0);
  for (int i = 0; i < N; ++i) {
    a[i] = 1LL * a[i] * b[i] % mod;
    a[i] = 1LL * a[i] * c[i] % mod;
  }
  FWHT_AND(a, 1);
  long long ans = 0;
  for (int i = 0; i < 17; ++i)
    ans = (ans + a[1 << i]) % mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}