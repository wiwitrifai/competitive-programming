#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e18;

multiset<long long> * st[N];

vector<pair<int, int> > g[N];

char s[N][12];
int d[N], c[N], sz[N], big[N];
long long mi[N], up[N], f[N];

int get_sz(int v, long long cost = 0) {
  sz[v] = 1;
  big[v] = -1;
  mi[v] = inf;
  f[v] = cost;
  for (auto it : g[v]) {
    get_sz(it.first, cost + it.second);
    sz[v] += sz[it.first];
    if (big[v] == -1 || sz[big[v]] < sz[it.first])
      big[v] = it.first;
    mi[v] = min(mi[v], mi[it.first] + it.second);
    up[it.first] = it.second;
  }
  if (mi[v] >= inf)
    mi[v] = 0;
}

void dfs(int v) {
  if (big[v] != -1) {
    st[big[v]] = st[v];
    dfs(big[v]);
    auto it = --st[v]->end();
    if (*it < mi[big[v]] + up[big[v]]) {
      st[v]->erase(it);
      st[v]->insert(mi[big[v]] + up[big[v]]);
    }
  }
  else
    st[v]->insert(0);
  for (auto e : g[v]) {
    int u = e.first;
    if (u == big[v]) continue;
    st[u] = new multiset<long long>();
    dfs(u);
    auto it = --st[u]->end();
    if (*it < mi[u] + up[u]) {
      st[u]->erase(it);
      st[u]->insert(mi[u] + up[u]);
    }
    cerr << st[v]->size() << endl;
    for (long long x : *st[u]) {
      st[v]->insert(x);
    }
  }
} 

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s %d %d", s[i], c+i, d+i);
    g[c[i]].emplace_back(i+m, d[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", c+m+i, d+m+i);
    g[c[m+i]].emplace_back(i, d[m+i]);
  }
  get_sz(0);
  st[0] = new multiset<long long>();
  dfs(0);
  vector<long long> val;
  for (long long x : *st[0])
    val.push_back(x);
  for (int i = 1; i <= n; ++i) {
    int ans = upper_bound(val.begin(), val.end(), f[i+m]) - val.begin();
    printf("%s %d\n", s[i], min(n - ans + 1, n));
  }

  return 0;
}