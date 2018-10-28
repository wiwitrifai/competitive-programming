#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int x[N], y[N];
long long ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, y+i);
    vp[i] = {x[i]-y[i], i};
  }
  sort(vp.begin(), vp.end());
  long long now = 0;
  for (int i = 0; i < n; ++i) {
    int id = vp[i].second;
    ans[id] = now + 1LL * i * y[id];
    now += x[id];
  }
  now = 0;
  for (int i = n-1; i >= 0; --i) {
    int id = vp[i].second;
    ans[id] += now + 1LL * (n-1-i) * x[id];
    now += y[id];
  }
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    int best = min(x[u]+y[v], x[v]+y[u]);
    ans[u] -= best;
    ans[v] -= best;
  }
  for (int i = 0; i < n; ++i)
    printf("%lld%c", ans[i], i == n-1 ? '\n' : ' ');
  return 0;
}