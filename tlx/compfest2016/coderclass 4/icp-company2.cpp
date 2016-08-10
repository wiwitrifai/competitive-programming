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
      mob[i] = -mob[now] * pp;
    else
      mob[i] = 0;
  }
  int inv2 = (mod+1)/2;
  inv3 = powmod(3, mod-2);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      g[j] = (g[j] + mob[i]) % mod;
    }
    g[i] = (1LL * inv2 * g[i]) % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    long long ans = 0;
    for(int d = 1; d <= a; d++) {
      int bd = b/d, ad = a/d;
      ans = (ans + ((1LL * g[d] * ((sum(bd - 1) - sum(bd - ad - 1) + sum2(bd - 1) - sum2(bd - ad - 1)) % mod)) % mod)) % mod;
    }
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}