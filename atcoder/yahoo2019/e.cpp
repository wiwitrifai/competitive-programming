#include <bits/stdc++.h>

using namespace std;

const int N = 303, mod = 998244353;

int a[N][N];

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      scanf("%d", a[i]+j);
  }
  int cnt = 0;
  for (int k = 0; k < c; ++k) {
    int idx = -1;
    for (int i = cnt; i < r; ++i) {
      if (a[i][k])
        idx = i;
    }
    if (idx == -1) continue;
    for (int i = 0; i < c; ++i)
      swap(a[cnt][i], a[idx][i]);
    for (int i = cnt+1; i < r; ++i) {
      if (a[i][k] == 0) continue;
      for (int j = 0; j < c; ++j) {
        a[i][j] ^= a[cnt][j];
      }
    }
    ++cnt;
  }
  long long ans = 1;
  for (int i = 0; i < cnt; ++i)
    ans = ans * 2 % mod;
  --ans;
  for (int i = 0; i < c-1 + r - cnt; ++i) {
    ans = ans * 2 % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}