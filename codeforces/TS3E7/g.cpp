#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 102;

long long dp[N][1<<10];
long long cnt[1<<10], C[N][N], unineg[1<<10];
int v[12];

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    p >>=1;
    b = (b * b) % mod;
  }
  return ret;
}
long long inv[N];
long long Comb(long long n, long long k) {
  long long ret = 1;
  for (int i = 0; i < k; i++) {
    ret = (ret * (n-i)) % mod;
    ret = (ret * inv[i+1]) % mod;
  }
  if (ret < 0)
    ret += mod;
  return ret;
}

int main() {
  inv[0] = 0;
  inv[1] = 1;
  for (int i = 2; i < N; i++)
    inv[i] = powmod(i, mod-2);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  a--;
  int m = 0;
  for (int i = 2; 1LL * i * i < k; i++) if ((k % i) == 0) {
    v[m] = 1;
    while ((k % i) == 0) {
      k /= i;
      v[m] *= i;
    }
    m++;
  }
  if (k > 1) {
    v[m++] = k;
  }
  int all = (1<<m);
  for (int i = 0; i < all; i++) {
    int now = 1;
    for (int j = 0; j < m; j++)
      if (i & (1<<j))
        now *= v[j];
    cnt[i] = b/now - a/now;
  }
  for (int i = 0; i < all; i++) {
    int now = cnt[0];
    for (int j = i; j > 0; j = (j-1)&i)
      if (__builtin_popcount(j) & 1)
        now = (now + mod - cnt[j]) % mod;
      else
        now = (now + cnt[j]) % mod;
    if (now < 0) now += mod;
    unineg[i] = now;
  }
  long long ans = 0;
  for (int i = 0; i < all; i++) {
    long long cur = Comb(n + unineg[i]-1, n);
    if (__builtin_popcount(i) & 1)
      ans = (ans + mod - cur) % mod;
    else
      ans = (ans + cur) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}