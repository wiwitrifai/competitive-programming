#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int n, m, k;

vector<pair<int, int>> bfs(int v) {
  vector<pair<int, int>> ret(n, make_pair(-1, -1));
  queue<int> que;
  ret[v] = {0, -1};
  que.push(v);
  while (!que.empty()) {
    v = que.front();
    que.pop();
    for (int u : g[v]) {
      if (ret[u].first != -1) continue;
      ret[u] = make_pair(ret[v].first + 1, v);
      que.push(u);
    }
  }
  return ret;
}

vector<int> col;
void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    col[u] = !col[v];
    dfs(u, v);
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  if (m == n-1) {
    col.resize(n);
    col[0] = 0;
    dfs(0);
    int cnt0 = 0;
    for (int i = 0; i < n; ++i)
      cnt0 += col[i] == 0;
    int big = 0;
    if (cnt0 < n-cnt0) {
      big = 1;
    }
    k = (k + 1) / 2;
    puts("1");
    for (int i = 0; i < n && k > 0; ++i) {
      if (col[i] != big) continue;
      printf("%d ", i+1);
      --k;
    }
    assert(k == 0);
    printf("\n");
    return 0;
  }
  auto dist = bfs(0);
  int x = -1, y = -1;
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) {
      if (u == dist[i].second || i == dist[u].second) continue;
      if (x == -1 || (dist[x].first + dist[y].first > dist[i].first + dist[u].first))
        x = i, y = u;
    }
  }
  vector<int> cycle;
  vector<int> nodex, nodey;
  while (x != y) {
    if (dist[x].first >= dist[y].first) {
      nodex.push_back(x);
      x = dist[x].second;
    } else {
      nodey.push_back(y);
      y = dist[y].second;
    }
  }
  nodex.push_back(x);
  reverse(nodey.begin(), nodey.end());
  cycle = nodex;
  for (int z : nodey)
    cycle.push_back(z);
  if ((int)cycle.size() <= k) {
    printf("2\n%d\n", (int)cycle.size());
    for (int z : cycle) {
      printf("%d ", z+1);
    }
  } else {
    printf("1\n");
    k = (k + 1) / 2;
    for (int j = 0; j + 1 < (int)cycle.size() && k > 0; j += 2) {
      printf("%d ", cycle[j]+1);
      --k;
    }
    assert(k == 0);
  }
  printf("\n");
  return 0;
}
