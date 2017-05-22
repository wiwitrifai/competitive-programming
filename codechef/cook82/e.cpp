#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5, mod = 1e9 + 7, inv2 = (mod+1)/2;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
int l[N], r[N], nodes, muncul[N];
long long dua[N], sdua[N];
int len, now;
char s[N];
void upd(int node = 1, int id = 0) {
  if (id == len) {
    sdua[node] = dua[node] += ((long long)mod-powmod(inv2, muncul[node]) + powmod(inv2, now+1)) % mod;
    muncul[node] = now+1;
    l[node] = r[node] = 0;
  }
  else {
    if (s[id] == 'L') {
      if (l[node] == 0) {
        l[node] = ++nodes;
        l[nodes] = r[nodes] = 0;
        dua[nodes] = sdua[nodes] = 0;
        muncul[nodes] = muncul[node] + 1;
      }
      upd(l[node], id+1);
    }
    else {
      if (r[node] == 0) {
        r[node] = ++nodes;
        l[nodes] = r[nodes] = 0;
        dua[nodes] = sdua[nodes] = 0;
        muncul[nodes] = muncul[node] + 1;
      }
      upd(r[node], id+1);
    }
    sdua[node] = (sdua[l[node]] + sdua[r[node]] + dua[node]) % mod;
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    l[0] = r[0] = 0;
    sdua[0] = dua[0] = 0;
    muncul[0] = 0;
    nodes = 1;
    l[nodes] = r[nodes] = 0;
    sdua[1] = dua[1] = 1;
    muncul[1] = 0;
    int q;
    now = 0;
    scanf("%d", &q);
    while (q--) {
      int cmd;
      scanf("%d", &cmd);
      if (cmd == 1) {
        int t;
        scanf("%d", &t);
        now += t;
      }
      else {
        scanf("%s", s);
        len = strlen(s);
        upd();
      }
      long long ans = sdua[1] * powmod(2, now+1) % mod;
      ans--;
      ans %= mod;
      while (ans < 0) ans += mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}