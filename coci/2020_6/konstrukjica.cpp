#include <bits/stdc++.h>

using namespace std;

long long calc(int n, vector<pair<int, int>> edge) {
  assert(1 <= n && n <= 1000 && edge.size() <= 1000);
  vector<vector<int>> g(n, vector<int>()), vis(n, vector<int>(n, 0));
  vector<int> din(n, 0);
  for (auto e : edge) {
    g[e.first].push_back(e.second);
    ++din[e.second];
  }
  vector<int> topo;
  for (int i = 0; i < n; ++i) {
    if (din[i]) continue;
    topo.push_back(i);
  }
  for (int x = 0; x < (int)topo.size(); ++x) {
    int v = topo[x];
    for (int u : g[v]) {
      vis[v][u] = 1;
      for (int i = 0; i < n; ++i) {
        if (!vis[i][v]) continue;
        vis[i][u] = 1;
      }
      --din[u];
      if (din[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  assert((int)topo.size() == n);
  vector<long long> dp(n, 0);
  dp[0] = 1;
  for (int u : topo) {
    for (int i = 0; i < n; ++i) {
      if (!vis[i][u]) continue;
      dp[u] -= dp[i];
    }
  }
  return dp[n-1];
}

void output(int n, vector<pair<int, int>> edges) {
  printf("%d %d\n", n, (int)edges.size());
  for (auto e : edges) {
    printf("%d %d\n", e.first + 1, e.second + 1);
  }
}

int main() {
  long long k;
  scanf("%lld", &k);
  int n = 1;
  vector<long long> val(1, 1);
  vector<pair<int, int>> edges;
  if (k == 0) {
    n = 4;
    edges.emplace_back(0, 1);
    edges.emplace_back(1, 2);
    edges.emplace_back(2, 3);
    // assert(calc(n, edges) == 0);
    output(n, edges);
    return 0;
  }
  long long now = 1, abk = k < 0 ? -k : k;
  while (now <= abk) {
    for (int i = 0; i < 3; ++i) {
      val.push_back(0);
      for (int j = 0; j < 3; ++j) {
        if (n - j - 1 < 0) continue;
        edges.emplace_back(n-j-1, n+i);
        if (j < 2)
          val[n+i] -= val[n-j-1];
      }
    }
    n += 3;
    now *= 2;
  }
  long long orik = k;
  if (k < 0) {
    k = -k;
  }
  else {
    for (auto & v : val)
      v *= -1;
  }
  vector<int> last;
  for (int i = 0; (1LL << i) <= k; ++i) {
    if (((k >> i) & 1) == 0) continue;
    int from = 1 + i * 3;
    if (val[from] > 0) {
      if ((1LL << (i+1)) > k) {
        last.push_back(from);
        last.push_back(from+1);
      }
      else {
        if (i > 0) {
          edges.emplace_back(from-3, n);
          edges.emplace_back(from-2, n);
          edges.emplace_back(from-1, n);
        }
        else {
          edges.emplace_back(from-1, n);
        }
        last.push_back(n);
        ++n;
      }
    }
    else {
      edges.emplace_back(from, n);
      edges.emplace_back(from+1, n);
      last.push_back(n);
      ++n;
      if ((1LL << (i+1)) > k) {
        edges.emplace_back(from, n);
        edges.emplace_back(from+1, n);
        last.push_back(n);
        ++n;
      }
    }
  }
  for (int u : last)
    edges.emplace_back(u, n);
  ++n;
  // assert(calc(n, edges) == orik);
  output(n, edges);
  return 0;
}
