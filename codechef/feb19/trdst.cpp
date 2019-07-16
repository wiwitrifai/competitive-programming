#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> cnt[N], cnt_par[N];
vector<pair<int, int> > centroids[N];

vector<int> g[N];
int k[N], live[N], sz[N], lv[N], bg[N];

void get_size(int v, int par = -1) {
  sz[v] = 1;
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  bg[v] = -1;
  for (int u : g[v]) {
    if (u == par) continue;
    if (!live[u]) continue;
    get_size(u, v);
    sz[v] += sz[u];
    if (bg[v] == -1 || sz[bg[v]] < sz[u])
      bg[v] = u;
  }
}

void get_cnt(int c, int v, int par = -1) {
  while (cnt_par[c].size() <= lv[v]+1) cnt_par[c].push_back(0);
  ++cnt_par[c][lv[v]+1];
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  while (cnt[c].size() <= lv[v]) cnt[c].push_back(0);
  ++cnt[c][lv[v]];
  centroids[v].emplace_back(c, lv[v]);
  for (int u : g[v]) {
    if (u == par) continue;
    if (!live[u]) continue;
    get_cnt(c, u, v);
  }
}

void centr_decomp(int v) {
  lv[v] = 0;
  get_size(v);
  int tot = sz[v];
  while (bg[v] != -1 && sz[bg[v]] * 2 >= tot) v = bg[v];
  get_cnt(v, v);
  live[v] = 0;
  for (int u : g[v]) {
    if (!live[u]) continue;
    centr_decomp(u);
  }
}

int calc(int v, int d) {
  int ret = 0;
  for (int i = 0; i < centroids[v].size(); ++i) {
    int c = centroids[v][i].first, idx = d - centroids[v][i].second;
    idx = min(idx, (int)cnt[c].size()-1);
    if (idx >= 0)
      ret += cnt[c][idx];
    if (i > 0) {
      idx = d - centroids[v][i-1].second;
      idx = min(idx, (int)cnt_par[c].size()-1);
      if (idx >= 0)
        ret -= cnt_par[c][idx];
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", k+i), k[i] = n - k[i];
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(live, live+n, 1);
  centr_decomp(0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j+1 < cnt[i].size(); ++j)
      cnt[i][j+1] += cnt[i][j];
    for (int j = 0; j+1 < cnt_par[i].size(); ++j)
      cnt_par[i][j+1] += cnt_par[i][j];
  }
  for (int i = 0; i < n; ++i) {
    int lo = 0, hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      int res = calc(i, mid);
      if (res <= k[i])
        lo = mid;
      else
        hi = mid-1;
    }
    printf("%d%c", lo, i == n-1 ? '\n' : ' ');
  }
  return 0;
}