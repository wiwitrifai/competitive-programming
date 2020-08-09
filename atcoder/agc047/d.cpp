#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 19, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long mul[N], inv[N], val[N];

int p[N], h, n, leaf;

long long sum[N];

void add(int v, long long x) {
  while (v > 0) {
    sum[v] += x;
    if (sum[v] >= mod)
      sum[v] -= mod;
    v >>= 1;
  }
}

long long get(int v) {
  long long ret = 0;
  while (v > 1) {
    int par = v >> 1;
    ret = (ret + (sum[par] - sum[v]) * inv[par]) % mod;
    v = par;
  }
  if (ret < 0)
    ret += mod;
  return ret;
}

void upd(int v, int x) {
  if (v * 2 > n) {
    int u = p[v - leaf] + leaf;
    long long cur = val[v];
    if (x < 0)
      cur = (mod - cur) % mod;
    add(u, cur);
  } else {
    upd(v * 2, x);
    upd(v * 2 + 1, x);
  }
}

long long solve(int v) {
  if (v * 2 > n) return 0;
  long long ret = 0;
  int lef = v * 2, rig = v * 2 + 1;
  upd(lef, +1);
  int from = rig, til = rig;
  while (from * 2 <= n) {
    from = from * 2;
    til = til * 2 + 1;
  }
  for (int i = from; i <= til; ++i) {
    ret = (ret + get(p[i - leaf] + leaf) * val[i]) % mod;
  }
  ret = (ret * inv[v]) % mod;
  upd(lef, -1);
  ret = (ret + solve(lef) + solve(rig)) % mod;
  if (ret < 0)
    ret += mod;
  return ret;
}

int main() {
  scanf("%d", &h);
  leaf = (1 << (h-1));
  n = (1 << h) - 1;
  mul[1] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    mul[i] = mul[i / 2] * i % mod;
    inv[i] = powmod(mul[i], mod - 2);
    inv[i] = inv[i] * inv[i] % mod;
    inv[i] = inv[i] * i % mod;
  }
  for (int i = 0; i < leaf; ++i) {
    scanf("%d", p+i);
    --p[i];
    val[leaf + i] = mul[leaf + i] * mul[leaf + p[i]] % mod;
  }
  printf("%lld\n", solve(1));
  return 0;
}
