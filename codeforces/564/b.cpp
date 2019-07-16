#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 998244353;

int deg[N], fac[N];

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    ++deg[u];
    ++deg[v];
  }
  int ans = 1LL * n * fac[deg[0]] % mod;
  for (int i = 1; i < n; ++i) {
    ans = 1LL * ans * fac[deg[i]] % mod;
  }
  printf("%d\n", ans);
  return 0;
}
