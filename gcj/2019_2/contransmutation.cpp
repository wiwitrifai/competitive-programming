#include <bits/stdc++.h>

using namespace std;

const int N  = 1e5 + 5, mod = 1e9 + 7;

vector<int> g[N], dag[N], elem[N];
int s[N], cc[N], din[N];

vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    elem[numCC].clear();
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      elem[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}
long long dp[N];
bool infi[N], ada[N];

void solve(int tc) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[i].clear();
    g[i].push_back(u);
    g[i].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", s+i);
  }
  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cntr = numCC = 0;
  S.clear();
  for(int i = 0; i < n; ++i)
    if(num[i] == -1)
      tarjanSCC(i);
  for (int i = 0; i < numCC; ++i) {
    dag[i].clear();
    din[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) {
      if (cc[u] == cc[i]) continue;
      dag[cc[i]].push_back(cc[u]);
      ++din[cc[u]];
    }
  }
  vector<int> topo;
  for (int i = 0; i < numCC; ++i) {
    if (din[i] == 0)
      topo.push_back(i);
  }
  for (int i = 0; i < topo.size(); ++i) {
    int v = topo[i];
    for (int u : dag[v]) {
      --din[u];
      if (din[u] == 0)
        topo.push_back(u);
    }
  }
  assert(topo.size() == numCC);
  fill(infi, infi+n, false);
  fill(ada, ada+n, false);
  fill(dp, dp+n, 0);
  int target = cc[0];
  for (int i = 0; i < n; ++i) {
    if (s[i] == 0) continue;
    int c = cc[i];
    ada[c] = 1;
    dp[c] += s[i];
    dp[c] %= mod;
  }
  for (int c : topo) {
    if (!ada[c]) {
      if (c == target) {
        printf("Case #%d: 0\n", tc);
        return;
      }
      continue;
    }
    if (c == target) {
      for (int e : elem[c]) {
        int u = g[e][0], v = g[e][1];
        if (cc[u] == c && cc[v] == c)
          infi[c] = 1;
      }
      if (infi[c]) {
        printf("Case #%d: UNBOUNDED\n", tc);
        return;
      }
      dp[c] %= mod;
      if (dp[c] < 0) dp[c] += mod;
      printf("Case #%d: %lld\n", tc, dp[c]);
      return;
    }
    for (int e : elem[c]) {
      for (int u : g[e])
        if (cc[u] == c)
          infi[c] = 1;
    }
    if (infi[c]) {
      for (int u : dag[c]) {
        ada[u] = 1;
        infi[u] = 1;
      }
      continue;
    }
    for (int u : dag[c]) {
      if (u == c) continue;
      dp[u] += dp[c];
      dp[u] %= mod;
      ada[u] = 1;
    }
  }
  assert(false);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
