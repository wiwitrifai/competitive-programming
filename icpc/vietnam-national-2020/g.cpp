#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, L = 5e5 + 5, LG = 20;

int label[N];
vector<int> fact[L];
vector<int> alive[L];
vector<int> nodes;
int in[N], out[N];
vector<pair<int, int>> g[N];
long long depth[N];

int sp[LG][N];

void dfs(int v, int par = -1) {
  in[v] = nodes.size();
  nodes.push_back(v);
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    depth[u] = depth[v] + e.second;
    dfs(u, v);
    nodes.push_back(v);
  }
  out[v] = nodes.size();
}

int getLca(int u, int v) {
  int l = in[u], r = in[v];
  if (l > r)
    swap(l, r);
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  int a = sp[lg][l], b = sp[lg][r-(1<<lg)+1];
  return depth[a] < depth[b] ? a : b;
}

bool isAncestor(int v, int par) {
  return in[par] <= in[v] && out[v] <= out[par];
}

vector<int> anc;
vector<long long> longest;


int solve() {
  int n;
  scanf("%d", &n);
  if (n == 0)
    exit(0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", label+i);
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  nodes.clear();
  depth[0] = 0;
  dfs(0);
  set<int> dset;
  for (int i = 0; i < (int)nodes.size(); ++i) {
    int v = nodes[i];
    if (in[v] == i) {
      for (int d : fact[label[v]]) {
        dset.insert(d);
        alive[d].push_back(v);
      }
    }
  }
  for (int i = 0; i < (int)nodes.size(); ++i)
    sp[0][i] = nodes[i];
  for (int i = 0; i + 1 < LG; ++i) {
    // if ((int)(1 << (i+1)) > nodes.size()) break;
    for (int j = 0; j + (1 << (i+1)) <= (int)nodes.size(); ++j) {
      int u = sp[i][j], v = sp[i][j+(1 << i)];
      sp[i+1][j] = depth[u] < depth[v] ? u : v;
    }
  }
  long long ans = 0;
  for (int d : dset) {
    if (alive[d].empty()) continue;
    long long best = 0;
    anc.clear();
    longest.clear();
    for (int v : alive[d]) {
      if (anc.empty()) {
        anc.push_back(v);
        longest.push_back(depth[v]);
        continue;
      }
      int lca = getLca(v, anc.back());
      long long cur = depth[lca];
      while (!anc.empty() && isAncestor(anc.back(), lca)) {
        if (cur >= depth[anc.back()]) {
          best = max(best, cur + longest.back() - depth[anc.back()] * 2LL);
        }
        cur = max(cur, longest.back());
        anc.pop_back();
        longest.pop_back();
        best = max(cur + depth[v] - 2LL * depth[lca], best);
      }
      anc.push_back(lca);
      longest.push_back(cur);
      if (lca != v) {
        anc.push_back(v);
        longest.push_back(depth[v]);
      }
    }
    while ((anc.size() >= 2)) {
      long long cur = longest.back();
      anc.pop_back();
      longest.pop_back();
      best = max(best, cur + longest.back() - depth[anc.back()] * 2LL);
      longest.back() = max(longest.back(), cur);
    }
    ans = max(ans, best * d);
  }
  printf("%lld\n", ans);
  for (int d : dset) {
    alive[d].clear();
  }
  return 0;
}


int main() {
  for (int i = 1; i < L; ++i) {
    for (int j = i; j < L; j += i)
      fact[j].push_back(i);
  }
  while (true) {
    solve();
  }
}
