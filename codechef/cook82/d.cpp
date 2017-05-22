#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int mod[] = {int(1e9 + 7), int(1e9 + 9)};
int p[] = {23, 31};
long long pp[N][2];
int a[N], hs[N][2];

void add(long long & le, long long ri, int mm) {
  le += ri;
  if (le < mm) le += mm;
  if (le >= mm) le -= mm;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  pp[0][0] = pp[0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      pp[i+1][j] = pp[i][j] * p[j] % mod[j];
    }
  }
  hs[0][0] = hs[0][1] = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    for (int j = 0; j < 2; j++) {
      long long cur = hs[i][j];
      if (a[u])
        add(cur, -pp[u][j], mod[j]);
      else
        add(cur, pp[u][j], mod[j]);
      if (a[v])
        add(cur, -pp[v][j], mod[j]);
      else
        add(cur, pp[v][j], mod[j]);
      cur %= mod[j];
      if (cur < 0) cur += mod[j];
      hs[i+1][j] = cur;
    }
    a[u] ^= 1;
    a[v] ^= 1;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    if (hs[l][0] == hs[r][0] && hs[l][1] == hs[r][1])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}