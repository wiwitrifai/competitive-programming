#include <bits/stdc++.h>

using namespace std;

const int N = 5050, inf = 1e8;

vector< int > adj[N];
int dist[N];
pair< int, pair< int, int > > store[N];

int main() {
  int n, m, w;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%d", &w);
  for (int i = 0; i < w; i++) {
    int c, k, p;
    scanf("%d %d %d", &c, &k, &p);
    c--;
    store[i] = {p, {c, k}};
  }
  sort(store, store+w);
  int q;
  scanf("%d", &q);
  while (q--) {
    int g, rr, a;
    scanf("%d %d %d", &g, &rr, &a);
    g--;
    fill(dist, dist+n, inf);
    queue< int > que;
    dist[g] = 0;
    que.push(g);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int v : adj[u]) if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        que.push(v);
      }
    }
    int l = 0, r = N;
    while (l < r) {
      int mid = (l + r) >> 1;
      long long cost = 0;
      int need = rr;
      for (int i = 0; i < w; i++) {
        if (dist[store[i].second.first] > mid)
          continue;
        int d = min(need, store[i].second.second);
        need -= d;
        cost += 1LL * d * store[i].first;
      }
      if (need || cost > a)
        l = mid + 1;
      else
        r = mid;
    }
    if (l == N)
      puts("-1");
    else
      printf("%d\n", l);
  }

  return 0;
}