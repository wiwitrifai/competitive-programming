#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
vector<pair<int, long long>> g[N];
const long long inf = 1e18;


long long solve(int n, vector<tuple<int, int, long long>> & edges) {
  assert((int)edges.size() == 2 * n - 3);
  if (n == 3) {
    assert(edges.size() == 3);
    vector<long long> w(3);
    for (int i = 0; i < 3; ++i)
      w[i] = get<2>(edges[i]);
    sort(w.begin(), w.end());
    long long ret = w[0] + w[1];
    ret += min(w[2], w[0] + w[1]);
    return ret % mod;
  }
  long long ret = 0;
  int s = -1, t = -1;
  int best = -1;
  for (auto & e : edges) {
    int u, v;
    long long w;
    tie(u, v, w) = e;
    if (u > v)
      swap(u, v);
    int cur = min(v-u, n-(v-u));
    if (cur > best) {
      s = u;
      t = v;
      best = cur;
    }
    if (w >= 0) {
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  assert(best > 1);
  vector<long long> ds(n, inf), dt(n, inf);
  auto dijkstra = [&](int from, vector<long long> & dist) {
    priority_queue<pair<long long, int>> pq;
    dist[from] = 0;
    pq.emplace(0, from);
    while (!pq.empty()) {
      int v;
      long long dv;
      tie(dv, v) = pq.top();
      dv = -dv;
      pq.pop();
      if (dv != dist[v]) continue;
      for (auto & e : g[v]) {
        int u = e.first;
        long long du = dv + e.second;
        if (du < dist[u]) {
          dist[u] = du;
          pq.emplace(-du, u);
        }
      }
    }
  };
  dijkstra(s, ds);
  dijkstra(t, dt);
  long long z = ds[t];
  vector<long long> slef, tlef, srig, trig;
  int cntlef = t - s - 1, cntrig = n - (2 + cntlef);
  for (int i = 0; i < n; ++i) {
    if (i == s ||i == t) continue;
    if (s <= i && i <= t) {
      ret = (ret + min(ds[i], dt[i]) * cntrig) % mod;
      if (ds[i] < dt[i])
        tlef.emplace_back(dt[i] - ds[i]);
      else
        slef.emplace_back(ds[i] - dt[i]);
    } else {
      ret = (ret + min(ds[i], dt[i]) * cntlef) % mod;
      if (ds[i] < dt[i])
        trig.emplace_back(dt[i] - ds[i]);
      else
        srig.emplace_back(ds[i] - dt[i]);
    }
  }
  ret %= mod;
  sort(slef.begin(), slef.end());
  sort(tlef.begin(), tlef.end());
  sort(srig.begin(), srig.end());
  sort(trig.begin(), trig.end());
  auto process = [&](vector<long long> & a, vector<long long> & b) {
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
      if (a[i] <= b[j]) {
        if (a[i] >= z) break;
        ret = (ret + a[i] * (b.size() - j)) % mod;
        ++i;
      } else {
        if (b[j] >= z) break;
        ret = (ret + b[j] * (a.size() - i)) % mod;
        ++j;
      }
    }
    ret = (ret + (z * (a.size() - i) % mod) * (b.size() - j)) % mod;
  };
  process(slef, trig);
  process(tlef, srig);
  ret = (ret + mod - z) % mod;
  for (int i = 0; i < n; ++i)
    g[i].clear();
  vector<tuple<int, int, long long>> lefedges, rigedges;
  int skip = t - s - 1;
  for (auto & e : edges) {
    int u, v;
    long long w;
    tie(u, v, w) = e;
    if (u > v)
      swap(u, v);
    if (u == s && v == t) {
      lefedges.emplace_back(u-s, v-s, z);
      rigedges.emplace_back(u, v-skip, z);
      continue;
    }
    if (s <= u && v <= t) {
      lefedges.emplace_back(u-s, v-s, w);
    } else {
      if (u > s)
        u -= skip;
      if (v > s)
        v -= skip;
      rigedges.emplace_back(u, v, w);
    }
  }
  ret = (ret + solve(t-s+1, lefedges) + solve(n - (t-s-1), rigedges)) % mod;
  if (ret < 0)
    ret += mod;
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  map<pair<int, int>, int> st;
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    int u = i;
    int v = i + 1;
    if (v >= n)
      v = 0;
    if (u > v)
      swap(u, v);
    st[make_pair(u, v)] = w;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    if (u > v)
      swap(u, v);
    auto e = make_pair(u, v);
    auto it = st.find(e);
    if (it != st.end()) {
      it->second = min(it->second, w);
    } else {
      st[e] = w;
    }
  }
  vector<set<int>> gs(n);
  for (auto & e : st) {
    gs[e.first.first].insert(e.first.second);
    gs[e.first.second].insert(e.first.first);
  }
  queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (gs[i].size() == 2)
      que.push(i);
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (gs[v].size() != 2) continue;
    auto it = gs[v].begin();
    int a = *it, b = *(++it);
    gs[v].clear();
    gs[a].erase(v);
    gs[b].erase(v);
    assert(a < b);
    pair<int, int> e = {a, b};
    if (!st.count(e)) {
      st[e] = -1;
      gs[a].insert(b);
      gs[b].insert(a);
    }
    if (gs[a].size() == 2)
      que.push(a);
    if (gs[b].size() == 2)
      que.push(b);
  }
  vector<tuple<int, int, long long>> edges;
  for (auto it : st) {
    edges.emplace_back(it.first.first, it.first.second, it.second);
  }
  int ans = solve(n, edges);
  printf("%d\n", ans);
  return 0;
}
