#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const long long inf = 1e18 + 18;

int a[N];
bool can[N];
int pre[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  fill(can, can+n, 1);
  fill(pre, pre+n+1, -1);
  for (int i = 0; i < m; ++i) {
    int s;
    scanf("%d", &s);
    can[s] = 0;
  }
  for (int i = 1; i <= k; ++i)
    scanf("%d", a+i);
  for (int i = 0, last = -1; i <= n; ++i) {
    if (can[i]) last = i;
    pre[i] = last;
  }
  long long ans = inf;
  for (int d = 1; d <= k; ++d) {
    int cur = 0;
    bool ok = 1;
    for (int i = 0; i < n;) {
      int x = pre[i];
      if (x == -1 || x <= i - d) {
        ok = 0;
        break;
      }
      i = x + d;
      ++cur;
    }
    if (ok)
      ans = min(ans, 1LL * cur * a[d]);
  }
  if (ans >= inf) ans = -1;
  printf("%lld\n", ans);
  return 0;
}