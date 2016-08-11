#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

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

int p[N], g[N], mob[N];

long long sum(int n) {
  if(n <= 0)
    return 0;
  return (1LL * n * (n+1)/2) % mod;
}

int inv3;
long long sum2(int n) {
  if(n <= 0)
    return 0;
  return (((1LL * sum(n) * (2 * n + 1)) % mod) * inv3) % mod;
}

int main() {
  p[1] = 1;
  for (int i = 2; i < N; i++) if(p[i] == 0) {
    for (long long j = 1LL * i * i; j < N; j += i)
      p[j] = i;
    p[i] = i;
  }
  mob[1] = 1;
  for (int i = 2; i < N; i++) {
    int pp = p[i];
    int now = i/pp;
    if (now % pp)
      mob[i] = -mob[now];
    else
      mob[i] = 0;
  }
  for (int i = 1; i < N; i++) {
    int val = powmod(i, mod-2);
    assert(((1LL * val * i) % mod) == 1);
    for (int j = i; j < N; j += i)
      g[j] = (g[j] + mob[j/i] * val) % mod;
    g[i] = (1LL * g[i] * i) % mod;
  }
  int t;
  int inv2 = (mod+1)/2;
  inv3 = powmod(3, mod-2);
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    long long ans = 0;
    for(int d = 1; d <= a; d++) {
      ans = (ans + (((1LL * g[d] * inv2) % mod) * ((sum(b/d - 1) - sum(b/d - a/d - 1) + sum2(b/d - 1) - sum2(b/d - a/d - 1)) % mod))) % mod;
    }
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}