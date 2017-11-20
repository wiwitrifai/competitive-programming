#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int sum[N], w[N], le[N], ri[N];

vector<long long> a[N];

long long dist(int c, int u, int v) {
  if (u > v) swap(u, v);
  long long cur = a[c][v] - a[c][u];
  return min(a[c].back() - cur, cur);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
      a[i].clear();
      int k;
      long long cur = 0;
      scanf("%d", &k);
      a[i].push_back(0);
      while (k--) {
        int x;
        scanf("%d", &x);
        a[i].push_back(cur += x);
      }
    }
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d %d %d", &u, &v, w+i);
      u--; v--;
      ri[i] = u;
      le[(i+1) % n] = v;
    }
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      tot += dist(i, le[i], ri[i]);
      sum[i] = tot;
      tot += w[i];
    }
    while (q--) {
      int x, y, u, v;
      scanf("%d %d %d %d", &x, &y, &u, &v);
      x--; y--; u--; v--;
      if (y > v) {
        swap(x, u);
        swap(y, v);
      }
      long long ans = sum[v] - sum[y] - dist(v, le[v], ri[v]) + dist(v, le[v], u) + dist(y, x, ri[y]);
      ans = min(ans, tot - sum[v] + sum[y] - dist(y, le[y], ri[y]) + dist(v, ri[v], u) + dist(y, x, le[y]));
      printf("%lld\n", ans);
    }
  }
  return 0;
}