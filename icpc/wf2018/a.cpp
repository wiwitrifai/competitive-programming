#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

vector<long long> tim[N];
int n, m;
LL k;

vector<vector<tuple<int, int, double> > > g[N];
vector<bool> vis[N];
vector<double> dp[N];
int a[N], b[N];
long long s[N], t[N];
double p[N];


double solve(int v, int id) {
  if (id >= tim[v].size()) return 0;
  if (v == 1) {
    if (tim[v][id] <= k) return 1;
    return 0;
  }
  if (vis[v][id]) return dp[v][id];
  double & ret = dp[v][id];
  vis[v][id] = 1;
  ret = solve(v, id+1);
  double up = ret;
  for (auto it : g[v][id]) {
    int u, to;
    double w;
    tie(u, to, w) = it;
    ret = max(ret, w * solve(u, to) + (1 - w) * up);
  }
  return ret;
}

int main() {
  scanf("%d%d", &m, &n);
  scanf("%lld", &k);
  ++k;
  for(int i = 0; i < m; ++i){
    scanf("%d %d %lld %lld %lf", a+i, b+i, s+i, t+i, p+i); ++t[i];
    tim[a[i]].push_back(s[i]);
    tim[b[i]].push_back(t[i]);
  }
  tim[0].push_back(0);
  tim[1].push_back(k);
  for (int i = 0; i < n; ++i) {
    sort(tim[i].begin(), tim[i].end());
    tim[i].erase(unique(tim[i].begin(), tim[i].end()), tim[i].end());
  }
  for (int i = 0; i < n; ++i) {
    g[i].resize(tim[i].size());
    vis[i].assign(tim[i].size(), 0);
    dp[i].resize(tim[i].size());
    for (int j = 0; j < tim[i].size(); ++j)
      g[i][j].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u = a[i], v = b[i];
    int from = lower_bound(tim[u].begin(), tim[u].end(), s[i]) - tim[u].begin();
    int to = lower_bound(tim[v].begin(), tim[v].end(), t[i]) - tim[v].begin();
    g[u][from].emplace_back(v, to, p[i]);
  }
  printf("%.20lf\n", solve(0, 0));
  return 0;
}
