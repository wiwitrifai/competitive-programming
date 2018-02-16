#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 21;
set<int> to[N], from[N];
int g[LG][LG], node[LG], pos[N];
int dp[LG][1 << LG];

void fail() {
  puts("There is no route, Karl!");
  exit(0);
}

void open(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}
int main() {
  open("king");
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    to[u].insert(v);
    from[v].insert(u);
  }
  memset(pos, -1, sizeof pos);
  queue<int> que;
  for (int i = 1; i <= n; ++i) {
    if (to[i].empty() || from[i].empty()) fail();
    if (to[i].size() == 1 || from[i].size() == 1) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    if (to[v].size() == 1) {
      int u = *to[v].begin();
      if (from[u].size() > 1) {
        for (int z : from[u]) {
          if (z == v) continue;
          assert(to[z].count(u));
          to[z].erase(u);
          if (to[z].size() == 1)
            que.push(z);
          else if (to[z].empty())
            fail();
        }
        from[u].clear();
        from[u].insert(v);
        que.push(u);
      }
    }
    if (from[v].size() == 1) {
      int u = *from[v].begin();
      if (to[u].size() > 1) {
        for (int z : to[u]) {
          if (z == v) continue;
          assert(from[z].count(u));
          from[z].erase(u);
          if (from[z].size() == 1)
            que.push(z);
          else if (from[z].empty())
            fail();
        }
        to[u].clear();
        to[u].insert(v);
        que.push(u);
      }
    }
  }
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (to[i].size() > 1) {
      node[c] = i;
      pos[i] = c;
      ++c;
    }
  }
  if (c > 0) {
    assert(c < LG);
    for (int i = 1; i <= n; ++i) {
      if (to[i].size() > 1) {
        for (int u : to[i]) {
          int v = u;
          while (to[v].size() == 1)
            v = *to[v].begin();
          g[pos[i]][pos[v]] = u;
        }
      }
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    int nmask = 1 << c;
    for (int mask = 0; mask < nmask; ++mask) {
      for (int v = 0; v < c; ++v) if (dp[v][mask] != -1) {
        for (int u = 0; u < c; ++u) {
          if (mask & (1 << u)) continue;
          if (!g[v][u]) continue;
          dp[u][mask | (1 << u)] = v;
        }
      }
    }
    if (dp[0][nmask-1] == -1)
      fail();
    int v = 0, mask = nmask -1;
    while (mask) {
      int u = dp[v][mask];
      mask ^= (1 << v);
      to[node[u]].clear();
      to[node[u]].insert(g[u][v]);
      v = u;
    }
  }
  int cnt = 0, v = 1;
  for (int i = 1; i <= n; ++i)
    if (to[i].size() != 1)
      fail();
  while (1) {
    ++cnt;
    v = *to[v].begin();
    if (cnt > n) fail();
    if (v == 1) break;
  }
  if (cnt != n)
    fail();
  printf("1");
  v = 1;
  while (1) {
    v = *to[v].begin();
    printf(" %d", v);
    if (v == 1) break;
  }
  printf("\n");
  return 0;
}