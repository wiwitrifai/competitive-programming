#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int p[N];
int d[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return false;
  if (-p[u] > -p[v]) swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}
pair<int, pair<int, int > > edge[N << 1];

int main() {
  int n, m, a;
  scanf("%d %d %d", &n, &m, &a);
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    edge[i] ={w, {u, v}};
  }
  sort(edge, edge+m);
  bool ok = 0;
  long long ans = -1;
  for (int i = 0; i < m; i++) {
    long long w = edge[i].first;
    int u = edge[i].second.first, v = edge[i].second.second;
    if (ok && w * w > ans) break;
    if (!merge(u, v)) {
      fill(d, d+n, -1);
      queue<int> q;
      q.push(u);
      d[u] = 1;
      while (!q.empty()) {
        int s = q.front(); q.pop();
        for (int t : g[s]) {
          if (d[t] != -1) continue;
          d[t] = d[s] + 1;
          q.push(t);
        }
        if (d[v] != -1) break;
      }
      long long cur = w * w + 1LL * a * d[v];
      if (!ok)
        ans = cur;
      else
        ans = min(cur, ans);
      ok = 1;
    }
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (ok)
    printf("%lld\n", ans);
  else
    puts("Poor girl");

  return 0;
}