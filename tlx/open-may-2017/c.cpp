#include <bits/stdc++.h>

using namespace std;

const int N = 10040;

int n, m, val[N];
set < int > vis[N];
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
vector< int > g[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", val+i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  queue< pair< int, int > > que;
  que.push(make_pair(0, val[0]));
  vis[0].insert(val[0]);
  while (!que.empty()) {
    auto it = que.front(); que.pop();
    int v = it.first, k = it.second;
    for (int u : g[v]) {
      int h = gcd(val[u], k);
      if (!vis[u].count(h)) {
        vis[u].insert(h);
        que.push(make_pair(u, h));
      }
    }
  }
  int ans = 0;
  for (int v : vis[n-1])
    ans = max(ans, v);
  printf("%d\n", ans);
  return 0;
}