#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5050, mod = 1e9 + 7;
 
long long dl[N][N], dr[N][N];
int x[N];
 
int main() {
  int n, e, k;
  scanf("%d %d %d", &n, &e, &k);
  bool ok = 1;
  for (int i = 0; i < k; ++i) {
    int p, t;
    scanf("%d %d", &p, &t);
    if (x[t]) ok = 0;
    x[t] = p;
  }
  if (!ok) {
    puts("0");
    return 0;
  }
  dl[0][1] = 1;
  dr[0][1] = 1;
  long long ans = 0;
  for (int i = 1; i <= e; ++i) {
    if (x[i]) {
      int p = x[i];
      long long now = (dl[i-1][p-1] + dr[i-1][p+1]) % mod;
      if (i == e)
        ans = now;
      for (int j = 1; j <= n; ++j) {
        dl[i-1][j] = dr[i-1][j] = 0;
        dl[i][j] = dr[i][j] = 0;
      }
      dl[i][p] = now;
      dr[i][p] = now;
      continue;
    }
    for (int j = 1; j <= n; ++j) {
      long long now = (dl[i-1][j-1] + dr[i-1][j+1]) % mod;
      dl[i][j] = (now + dl[i-1][j-1] + dl[i-1][j]) % mod;
      if (i > 1)
        dl[i][j] = (dl[i][j] + mod - dl[i-2][j-1]) % mod;
      dr[i][j] = (now + dr[i-1][j+1] + dr[i-1][j]) % mod;
      if (i > 1)
        dr[i][j] = (dr[i][j] + mod - dr[i-2][j+1]) % mod;
    }
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}