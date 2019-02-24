#include <bits/stdc++.h>

using namespace std;

const int N = 5050, inf = 1e9 + 7;

int mi[N], cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  fill(mi, mi+n+1, inf);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    int d = b - a;
    if (d < 0)
      d += n;
    --a;
    mi[a] = min(mi[a], d);
    ++cnt[a];
  }
  for (int i = 0; i < n; ++i) {
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
      int now = i + j;
      if (now >= n) now -= n;
      if (cnt[now] == 0) continue;
      long long cur = 1LL * (cnt[now] - 1) * n + j + mi[now];
      ans = max(ans, cur);
    }
    printf("%lld%c", ans, i == (n-1) ? '\n' : ' ');
  }
  return 0;
}