#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7, M = 105, mod = 1e9 + 7;
int a[N], p[N], bef[N][M];
long long powmod(long long b, long long pw) {
  long long ret = 1;
  for (; pw; pw >>= 1, b = (b * b) % mod)
    if (pw & 1) ret = (ret * b) % mod;
  return ret;
}
long long c[N], koef[N];

int main() {
  int n, m;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int now = -1;

  for (int i = 0; i < n; i++) {
    while (now >= 0 && a[i] != a[now]) now = p[now];
    p[i] = now;
    now++;
  }
  for (int i = 0; i < n; i++) {
    bef[i][a[i]] = i;
    int now = i == 0 ? -1 : p[i-1]+1;
    for (int j = 1; j <= m; j++) {
      if (j == a[i]) continue;
      if (now < 0)
        bef[i][j] = -1;
      else
        bef[i][j] = bef[now][j];
    }
  }
  long long one = powmod(m, mod-2);
  for (int i = 0; i < n; i++) {
    koef[i] = 0;
    c[i] = 1;
    for (int j = 1; j <= m; j++) {
      int u = bef[i][j] + 1;
      if (u > i)
        continue;
      if (u == i)
        koef[i] = (koef[i] + one) % mod;
      else {
        koef[i] = (koef[i] + one * koef[u]) % mod;
        c[i] = (c[i] + one * c[u]) % mod;
      }
    }
    long long now = powmod(1 - koef[i], mod-2);
    c[i] = (c[i] * now) % mod;
    koef[i] = (one * now) % mod;
    if (c[i] < 0)
      c[i] += mod;
    if (koef[i] < 0) koef[i] += mod;
    for (int j = 0; j < i; j++) {
      c[j] = (c[j] + koef[j] * c[i]) % mod;
      koef[j] = (koef[j] * koef[i]) % mod;
    }
    c[0] %= mod;
    if (c[0] < 0)
      c[0] += mod;
    cout << c[0] << "\n";
  }
  return 0;
}