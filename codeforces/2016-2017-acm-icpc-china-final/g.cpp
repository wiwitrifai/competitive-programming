#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 18, inf = 1e9 + 7;

int p[N];
map<int, int> cnt[N];
pair<int, int> best[N];

vector< pair<int, int> > ans[N];
int par[LN][N], ma[LN][N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v, int w) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (cnt[u].size() > cnt[v].size())
    swap(u, v);
  for (auto it : cnt[u]) {
    int now = it.second + cnt[v][it.first];
    pair<int, int> nbest = {now, -it.first};
    cnt[v][it.first] = now;
    if (best[v] < nbest)
      best[v] = nbest;
  }
  ans[v].push_back({w, -best[v].second});
  p[u] = v;
  par[0][u] = v;
  ma[0][u] = w;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d:\n", tc);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d", &c);
      p[i] = -1;
      best[i] = {1, -c};
      cnt[i].clear();
      cnt[i][c] = 1;
      ans[i].clear();
      ans[i].push_back({0, c});
      par[0][i] = i;
      ma[0][i] = inf;
    }
    vector<pair<int, pair<int, int > > > edge;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    for (auto e : edge) {
      merge(e.second.first, e.second.second, e.first);
    }
    for (int i = 0; i + 1 < LN; i++) {
      for (int v = 0; v < n; v++) {
        par[i+1][v] = par[i][par[i][v]];
        ma[i+1][v] = max(ma[i][v], ma[i][par[i][v]]);
      }
    }
    int q, last = 0;
    scanf("%d", &q);
    while (q--) {
      int x, w;
      scanf("%d %d", &x, &w);
      x ^= last;
      w ^= last;
      x--;
      for (int i = LN-1; i >= 0; i--) {
        if (ma[i][x] <= w) {
          x = par[i][x];
        }
      }
      auto it = lower_bound(ans[x].begin(), ans[x].end(), make_pair(w+1, -1));
      it--;
      last = it->second;
      printf("%d\n", last);
    }
  }
  return 0;
}