#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 9;

long long fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long ret = 1;
  while(p) {
    if(p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}
long long C(int n, int k) {
  if(k < 0 || n < k)
    return 0;
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}

long long polyhedron_coloring(int v, int n) {
  switch(v) {
    case 4 : 
      return (((powmod(n, 4) + 11LL*powmod(n, 2)) % mod) * powmod(12, mod-2)) % mod;
    case 6 :
      return (((powmod(n, 6) + 3LL*powmod(n, 4) + 12LL*powmod(n, 3) + 8LL*powmod(n, 2)) % mod) * powmod(24, mod-2)) % mod;
    case 8 :
      return (((powmod(n, 8) + 17LL*powmod(n, 4) + 6LL*powmod(n, 2)) % mod) * powmod(24, mod-2)) % mod;
    case 12 :
      return (((powmod(n, 12) + 15LL*powmod(n, 6) + 44LL*powmod(n, 4)) % mod) * powmod(60, mod-2)) % mod;
    case 20 :
      return (((powmod(n, 20) + 15LL*powmod(n, 10) + 20LL*powmod(n, 8) + 24LL*powmod(n, 4)) % mod) * powmod(60, mod-2)) % mod;
    default :
      return 0;
  }
}

int f[7], nf;
long long dp[N][25][25], mul[25][25];
int poly_type[] = {4, 6, 8, 12, 20};
int n, k;
vector< int > ch[N];

long long solve(int v, int id, int kk) {
  long long & ret = dp[v][id][kk];
  if(ret > -1)
    return ret;
  ret = 1;
  for(int u : ch[v]) {
    long long now = 0;
    for(int i = 0; i<nf; i++) if(i != id) {
      for(int j = 1; j<=f[i]; j++) if(j <= k-kk) {
        now += (((C(k-kk, j) * mul[f[i]][j]) % mod) * solve(u, i, j)) % mod;
        now %= mod;
      }
    }
    ret = (ret * now) % mod;
  }
  if(ret < 0)
    ret += mod;
  return ret;
}

int main() {
  fac[0] = inv[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  for(int i = 0; i<5; i++) {
    int now = poly_type[i];
    for(int j = 1; j<=now; j++) {
      mul[now][j] = polyhedron_coloring(now, j);
      for(int h = 1; h<j; h++) {
        mul[now][j] -= (C(j,h) * mul[now][h]) % mod;
        mul[now][j] %= mod;
      }
      if(mul[now][j] < 0)
        mul[now][j] += mod;
    }
  }
  scanf("%d%d%d", &n, &k, &nf);
  for(int i = 0; i<nf; i++) {
    scanf("%d", f+i);
  }
  for(int i = 1; i<n; i++) {
    int v;
    scanf("%d", &v);
    ch[v-1].push_back(i);
  }
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  ma = min(ma, k);
  for(int i = 0; i<nf; i++) {
    for(int j = 1; j<=f[i]; j++) {
      ans += (((C(k, j) * mul[f[i]][j]) % mod) * solve(0, i, j)) % mod;
      ans %= mod;
    }
  }
  if(ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}