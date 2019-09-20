#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N], tree[N];

int comp[N], low[N], num[N], tmp_cnt = 0, ncomp = 0;
vector<int> nodes;
int w[N], cnt[N];

long long tot[N];

void dfs(int v, int par = -1) {
  nodes.push_back(v);
  low[v] = num[v] = tmp_cnt++;
  for (int u : g[v]) {
    if (num[u] == -1) {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
    }
    else if (u != par) {
      low[v] = min(low[v], num[u]);
    }
  }
  if (low[v] == num[v]) {
    while (1) {
      int now = nodes.back();
      nodes.pop_back();
      comp[now] = ncomp;
      ++cnt[ncomp];
      if (now == v)
        break;
    }
    ++ncomp;
  }
}

bool dfs2(int v, int par = -1) {
  bool ret = cnt[v] > 1;
  for (int u : tree[v]) {
    if (u == par) continue;
    ret |= dfs2(u, v);
  }
  if (ret)
    cnt[v] = max(2, cnt[v]);
  return ret;
}

long long solve(int v, int par = -1) {
  long long ret = 0;
  for (int u : tree[v]) {
    if (u == par) continue;
    ret = max(ret, solve(u, v));
  }
  ret += tot[v];
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", w+i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s;
  scanf("%d", &s);
  --s;
  memset(num, -1, sizeof num);
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    tot[comp[i]] += w[i];
    for (int u : g[i])
      if (comp[u] != comp[i])
        tree[comp[i]].push_back(comp[u]);
  }
  s = comp[s];
  int root = -1;
  for (int i = 0; i < ncomp; ++i) {
    if (cnt[i] > 1)
      root = i;
  }
  if (root != -1) {
    root = s;
    dfs2(root);
    for (int i = 0; i < ncomp; ++i) {
      if (i == root || cnt[i] < 2) continue;
      tot[root] += tot[i];
      tot[i] = 0;
    }
  }
  printf("%lld\n", solve(s));
  return 0;
}
