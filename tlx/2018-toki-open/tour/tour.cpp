#include "tour.h"

#include <bits/stdc++.h>
using namespace std;

const int N = 303;

vector<int> g[N];

int match[N], matched[N], vis[N];
int dfs(int v) {
  if (vis[v]) return false;
  vis[v] = 1;
  for (int u : g[v])
    if (match[u] == -1 || dfs(match[u]))
      return match[u] = v, matched[v] = u, true;
  return false;
}

int getShortestTour(int N, std::vector<std::string> S) {
  for (int i = 0; i < N; ++i)
    g[i].clear();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      if (S[i][j] == '.')
        g[i].push_back(j);
  }
  memset(match, -1, sizeof match);
  memset(matched, -1, sizeof matched);
  int ans = 0;
  while (1) {
    fill(vis, vis+N, 0);
    bool ada = 0;
    for (int i = 0; i < N; ++i)
      if (matched[i] == -1 && dfs(i)) {
        ada = 1;
        ++ans;
      }
    if (!ada) break;
  }
  return 2 * (N-1) - min(ans, N-1);
}
