// TLE
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, A = 1e4 + 4;

vector<int> fact[A];
vector<pair<int, int> > g[N];
vector<int> node[A];
vector<tuple<int, int, int> > edge[A];
int a[N], live[N];

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

int sz[N], bg[N];
void get_sz(int v, int par = -1) {
  sz[v] = 1;
  bg[v] = -1;
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par || !live[u]) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    if (bg[v] == -1 || sz[bg[v]] < sz[u])
      bg[v] = u;
  }
}

int sn = 0;
tuple<int, long long, int> S[N];
void dfs(int v, int par, int id, int mi, long long lv) {
  mi = min(mi, a[v]);
  S[sn++] = make_tuple(mi, lv, id);
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par || !live[u]) continue;
    dfs(u, v, id, mi, lv+it.second);
  }
}

bool lewat[A];

long long centroid(int v) {
  get_sz(v);
  int tot = sz[v];
  long long ret = 0;
  while (bg[v] != -1 && sz[bg[v]] * 2 >= tot) v = bg[v];
  int cnt = 0;
  sn = 0;
  for (auto it : g[v]) { 
    int u = it.first;
    if (!live[u]) continue;
    dfs(u, v, cnt, a[v], it.second);
    ++cnt;
  }
  sort(S, S+sn);
  pair<long long, int> best1(0, -1), best2(0, -1);
  for (int i = sn-1; i >= 0; --i) {
    int mi, id;
    long long lv;
    tie(mi, lv, id) = S[i];
    long long cur = 0;
    if (best1.second != id)
      cur = best1.first;
    else
      cur = best2.first;
    ret = max(ret, 1LL * (lv + cur) * mi);
    if (lv >= best1.first) {
      if (best1.second == id)
        best1.first = lv;
      else
        best2 = best1, best1 = {lv, id};
    }
    else if (lv >= best2.first && best1.second != id) {
      best2 = {lv, id};
    }
  }
  live[v] = 0;
  for (auto it : g[v]) {
    int u = it.first;
    if (!live[u]) continue;
    ret = max(ret, centroid(u));
  }
  return ret;
}

int main() {
  for (int i = 1; i < A; ++i) {
    for (int j = i; j < A; j += i)
      fact[j].push_back(i);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < A; ++i)
      edge[i].clear(), node[i].clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      for (int f : fact[a[i]])
        node[f].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w); --u, --v;
      int g = gcd(a[u], a[v]);
      for (int f : fact[g])
        edge[f].emplace_back(u, v, w);
    }
    long long ans = 0;
    fill(lewat, lewat+A, 0);
    for (int f = 1; f < A; ++f) {
      if (node[f].empty() || lewat[f]) continue;
      for (int v : node[f]) {
        live[v] = 1;
        g[v].clear();
      }
      for (auto e : edge[f]) {
        int u, v, w;
        tie(u, v, w) = e;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
      }
      for (int v : node[f]) if (live[v]) {
        ans = max(ans, 1LL * f * centroid(v));
      }
      for (int e : fact[f])
        if (node[e].size() == node[f].size())
          lewat[e] = 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}