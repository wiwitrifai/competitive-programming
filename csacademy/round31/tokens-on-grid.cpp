#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 16, M = 1024, mod = 1e9 + 7;

char s[16][M];

int mul[N], c[26];
bool ss[N];
long long ans[N];
long long res[20];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int nn = 1 << n;
  for (int i = 0; i < nn; i++)
    ans[i] = 1;
  for (int j = 0; j < m; j++) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '.') continue;
      c[s[i][j]-'a'] |= 1 << i;
    }
    mul[0] = 1;
    for (int mask = 1; mask < nn; mask++) {
      int k = 31-__builtin_clz(mask);
      mul[mask] = mul[mask^(1<<k)];
      if (s[k][j] != '.') {
        int com = __builtin_popcount(mask & c[s[k][j]-'a']);
        mul[mask] += 1 << (com-1);
      }
    }
    for (int mask = 0; mask < nn; mask++) {
      ans[mask] = ans[mask] * mul[mask] % mod;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < nn; mask++) {
      if (mask & (1<<i)) {
        ans[mask] -= ans[mask^(1<<i)];
        if (ans[mask] < 0) ans[mask] += mod;
      }
    }
  }
  for (int i = 0; i < nn; i++) {
    int k = n-__builtin_popcount(i);
    res[k] += ans[i];
    if (res[k] >= mod) res[k] -= mod;
  }
  for (int i = 0; i <= n; i++) {
    res[i] %= mod;
    if (res[i] < 0) res[i] += mod;
    printf("%lld ", res[i]);
  }
  printf("\n");
  return 0;
}