#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

vector<int> g[N];
int vis[N];

pair<int, int> dfs(int v, int col) {
  if (vis[v] != -1) {
    if (vis[v] != col) {
      puts("NO");
      exit(0);
    }
    return make_pair(0, 0);
  }
  pair<int, int> ret = {0, 0};
  if (col)
    ++ret.second;
  else
    ++ret.first;
  vis[v] = col;
  for (int u : g[v]) {
    auto res = dfs(u, !col);
    ret.first += res.first;
    ret.second += res.second;
  }
  return ret;
}
vector<int> snode;
vector<pair<int, int>> sz;
int mem[N][N];

int ans[N];

void assign(int v, int col) {
  if (vis[v] == col) {
    return;
  }
  vis[v] = col;
  for (int u : g[v]) {
    assign(u, !col);
  }
}

int dp(int id, int s) {
  if (s < 0)
    return 0;
  if (id == (int)sz.size()) {
    return s == 0;
  }
  int & ret = mem[id][s];
  if (ret != -1)
    return ret;
  ret = dp(id+1, s-sz[id].first);
  if (ret)
    return ret;
  ret = dp(id+1, s-sz[id].second);
  return ret;
}

void backtrack(int id, int s) {
  if (id == (int)sz.size())
    return;
  if (dp(id+1, s-sz[id].first)) {
    backtrack(id+1, s-sz[id].first);
  } else {
    assert(dp(id+1, s-sz[id].second));
    assign(snode[id], 1);
    backtrack(id+1, s-sz[id].second);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  memset(vis, -1, sizeof vis);
  for (int i = 0; i < n; ++i) {
    if (vis[i] != -1) continue;
    snode.push_back(i);
    auto res = dfs(i, 0);
    sz.emplace_back(res);
  }
  memset(mem, -1, sizeof mem);
  if (!dp(0, b)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  backtrack(0, b);
  for (int i = 0; i < n; ++i) {
    int now = vis[i];
    if (now == 0)
      now = 2;
    else {
      if (a > 0) {
        now = 1;
        --a;
      } else {
        now = 3;
      }
    }
    printf("%d", now);
  }
  printf("\n");
  return 0;
}
