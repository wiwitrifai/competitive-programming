#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ans = N + 1;
long long cnt = 0;

map<int, int> mp;

void add(int s) {
  ++mp[s];
}
void rem(int s) {
  auto it = mp.find(s);
  assert(it != mp.end() && it->second > 0);
  --it->second;
  if (it->second == 0)
    mp.erase(it);
}

vector<int> g[N];
int sz[N];
void get_sz(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
  }
}
int n;

set<pair<int, int>> st;
void dfs(int v = 0, int par = -1) {
  st.clear();
  int sisa = n - sz[v];
  auto it = mp.lower_bound((sisa + 1) / 2);
  if (it != mp.end()) {
    int x = it->first, y = sisa - it->first;
    if (x > y)
      swap(x, y);
    st.insert({x, y});
  }
  if (it != mp.begin()) {
    --it;
    int x = it->first, y = sisa - x;
    if (x > y)
      swap(x, y);
    st.insert({x, y});
  }
  for (auto pp : st) {
    int x = pp.first, y = pp.second, z = sz[v];
    int cur = max(abs(x - z), max(abs(x-y), abs(y-z)));
    if (cur > ans) continue;
    long long ada = 0;
    if (x == y) {
      auto it2 = mp.find(x);
      if (it2 != mp.end())
        ada = it2->second;
    }
    else {
      auto it2 = mp.find(x);
      auto it3 = mp.find(y);
      if (it2 != mp.end())
        ada += it2->second;
      if (it3 != mp.end())
        ada += it3->second;
    }
    if (cur < ans && ada > 0) {
      cnt = 0;
      ans = cur;
    }
    cnt += ada;
  }
  for (int u : g[v]) {
    if (u == par) continue;
    add(n - sz[u]);
    dfs(u, v);
    rem(n - sz[u]);
  }
  add(sz[v]);
}

int main() {
  scanf("%d", &n);
  ans = n+1;
  cnt = 0;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_sz(0);
  dfs(0);
  printf("%d %lld\n", ans * 2, cnt);
  return 0;
}
