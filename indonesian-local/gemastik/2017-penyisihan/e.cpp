#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8;

int a[N], b[N], c[N];
int ac[N], bc[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
      ac[i] = bc[i] = inf;
    for (int i = 0; i < n; i++)
      scanf("%d", a+i), ac[a[i] % m] = min(ac[a[i] % m], a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", b+i), bc[b[i] % m] = min(bc[b[i] % m], b[i]);
    for (int i = 0; i < m; i++)
      scanf("%d", c+i);
    long long ans = 1e18;
    sort(ac, ac+m);
    sort(bc, bc+m);
    for (int i = 0; i < m; i++) {
      if (ac[i] >= inf) break;
      for (int j = 0; j < m; j++) {
        if (bc[j] >= inf) break;
        long long cur = 1LL * ac[i] * bc[j];
        if (cur >= ans) break;
        cur += c[cur % m];
        ans = min(ans, cur);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}