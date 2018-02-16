#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> g[N];
int sz[N], num[N], low[N], cntr, cnt[N];
vector<pair<int, int> > cycle[N];
int nblock = 0;
long long ans = 0;
int n, m;

vector<pair<int, int> > S;
int root = 0, rootChildren = 0;
void dfs(int v = 0, int par = -1) {
  num[v] = low[v] = ++cntr;
  cnt[v] = 0;
  sz[v] = 1;
  for (int u : g[v]) if (num[u] == -1) {
    S.emplace_back(v, u);
    if (v == root)
      ++rootChildren;
    dfs(u, v);
    sz[v] += sz[u];
    if (low[u] > num[v]) {
      ans += 1LL * (n - sz[u]) * sz[u] - 1;
      cnt[v] += 1 + cnt[u];
    }
    if ((v == root && rootChildren > 1) || (v != root && low[u] >= num[v])) {
      while (1) {
        auto it = S.back(); S.pop_back();
        cycle[nblock].push_back(it);
        if (it == make_pair(v, u)) break;
      }
      ++nblock;
    }
    low[v] = min(low[u], low[v]);
  }
  else if (u != par && low[v] > num[u]) {
    low[v] = min(low[v], num[u]);
    S.emplace_back(v, u);
  }
}
int vis[N];
void sebar(int v) {
  vis[v] = 1;
  for (int u : g[v]) {
    if (low[u] > num[v])
      cnt[u] = cnt[v];
    if (!vis[u])
      sebar(u);
  }
}

void open(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}

int main() {
  open("cactus");
  scanf("%d %d", &n, &m);
  while (m--) {
    int k, u, v;
    scanf("%d %d", &k, &u);
    --u;
    for (int i = 1; i < k; ++i) {
      scanf("%d", &v); --v;
      g[u].push_back(v);
      g[v].push_back(u);
      u = v;
    }
  }
  nblock = cntr = 0;
  memset(num, -1, sizeof num);
  dfs(0);
  if (S.size() > 0) {
    cycle[nblock++] = S;
    S.clear();
  }
  sebar(0);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    ++mp[cnt[i]];
  }
  long long add = 0;
  for (auto it : mp) {
    if (it.first == 0) continue;
    int v = it.first, c = it.second;
    assert((c % (v+1)) == 0);
    c /= v+1;
    add += c * (1LL * v * (v+1) / 2 - v);
  }
  for (int i = 0; i < nblock; ++i) {
    if (cycle[i].size() < 2) continue;
    int elem = cycle[i].size();
    long long cur = elem, addnow = add;
    for (auto it : cycle[i]) {
      int c = cnt[it.first];
      cur += c;
      addnow -= (1LL * c * (c+1) / 2 - c);
    }
    cur = cur * (cur - 1) / 2 - cur;
    ans += elem * (cur + addnow);
  }
  cout << ans << endl;
  return 0;
}