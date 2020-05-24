#include <bits/stdc++.h>
 
using namespace std;
 
const int S = 500, SSS = S * S * S, N = 1e5 + 5, mod = 998244353;
 
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
 
const int base = powmod(10, 18);
 
vector<int> g[N];
 
vector<pair<int, int>> independent(int n, vector<pair<int ,int>> & edges) {
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (auto e : edges) {
    g[e.first].push_back(e.second);
    g[e.second].push_back(e.first);
  }
  vector<bool> done(n, false), mark(n);
  int cnt = 0;
  vector<pair<int, int>> res;
  while (cnt < n) {
    mark = done;
    int hig = -1, sum = 0;
    for (int v = n-1; v >= 0; --v) {
      if (mark[v]) continue;
      ++cnt;
      done[v] = 1;
      hig = max(hig, v+1);
      sum = (sum + powmod(base, v+1)) % mod;
      for (int u : g[v]) {
        mark[u] = 1;
      }
    }
    res.emplace_back(hig, sum);
  }
  return res;
}
 
vector<pair<int, int>> read_edges() {
  int m;
  scanf("%d", &m);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &edges[i].first, &edges[i].second);
    --edges[i].first;
    --edges[i].second;
  }
  return edges;
}
 
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> ex = read_edges();
  vector<pair<int, int>> ey = read_edges();
  vector<pair<int, int>> ez = read_edges();
  vector<pair<int, int>> rx = independent(n, ex);
  vector<pair<int, int>> ry = independent(n, ey);
  vector<pair<int, int>> rz = independent(n, ez);
  assert(rx.size() < S);
  assert(ry.size() < S);
  assert(rz.size() < S);
  long long ans = 0;
  for (int i = 0; i < (int)rx.size(); ++i) {
    for (int j = 0; j < (int)ry.size(); ++j) {
      int k = i^j;
      if (k < (int)rz.size()) {
        long long cur = rx[i].second * (long long)ry[j].second % mod;
        ans = (ans + cur * rz[k].second) % mod;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}