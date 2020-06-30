#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 998244353;

int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < m; ++i)
    scanf("%d", b+i);
  int id = n-1;
  int ans = 1;
  for (int i = m-1; i >= 0; --i) {
    while (id >= 0 && a[id] > b[i]) --id;
    if (id < 0 || a[id] != b[i]) {
      puts("0");
      return 0;
    }
    int cnt = 0;
    while (id >= 0 && a[id] >= b[i]) {
      ++cnt;
      --id;
    }
    if (i > 0)
      ans = 1LL * ans * cnt % mod;
  }
  if (id >= 0)
    ans = 0;
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);
  return 0;
}
