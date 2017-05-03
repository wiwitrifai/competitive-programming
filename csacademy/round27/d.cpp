#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
const long long inf = 1e18;
int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}
pair< int, pair< int, int > > ed[N];
int n, x, m;
int main() {
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w); u--; v--;
    ed[i] = {w, {u, v}};
  }
  memset(p, -1, sizeof p);
  long long ans = 0;
  sort(ed, ed+m);
  for (int i = 0; i < m; ++i) {
    int u = ed[i].second.first, v = ed[i].second.second, w = ed[i].first;
    u = find(u), v = find(v);
    if (u == v) continue;
    if (w > x) continue;
    if (w == x) ans += 1LL * p[u] * p[v];
    merge(u, v); 
  }
  printf("%lld\n", ans);

  return 0;
}