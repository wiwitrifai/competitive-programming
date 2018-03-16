#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;


vector<pair<int, int> > g[N];
tuple<int, int, int> edge[N];
vector<int> vk;
long long ans = 0;
int sz[N], bg[N], live[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  bg[v] = -1;
  for (auto it : g[v]) {
    int u = it.first;
    if (!live[u] || u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    if (bg[v] == -1 || sz[bg[v]] < sz[u])
      bg[v] = u;
  }
}
vector<pair<int, int> > s;
void get_m(int v, int par, int mi, int ma) {
  s.emplace_back(mi, ma);
  for (auto it : g[v]) {
    int u = it.first;
    if (!live[u] || u == par) continue;
    get_m(u, v, min(mi, it.second), max(ma, it.second));
  }
}

vector<pair<int, int> > all;

int n;
struct FEN {
  int bit[N];
  FEN() { memset(bit, 0, sizeof bit); }
  void upd(int x, int val) {
    for (; x; x -= x&-x) {
      bit[x] += val;
      if (bit[x] >= mod) bit[x] -= mod;
    }
  }

  int get(int x) {
    int ret = 0;
    for (; x <= n; x += x&-x) {
      ret += bit[x];
      if (ret >= mod) ret -= mod;
    }
    return ret;
  }
};

FEN sum, cnt;

long long calc(vector<pair<int, int> > & e) {
  sort(e.begin(), e.end());
  int m = e.size();
  long long ret = 0;
  int last = 0;
  for (int i = m-1; i >= 0; --i) {
    ret = (ret + vk[e[i].first] * 1LL * (sum.get(e[i].second+1))) % mod;
    long long cur = (last-cnt.get(e[i].second+1)) * 1LL * vk[e[i].second] % mod;
    ret = (ret + vk[e[i].first] * 1LL * (cur)) % mod;
    sum.upd(e[i].second+1, vk[e[i].second]);
    cnt.upd(e[i].second+1, 1);
    ++last;
  }
  for (int i = 0; i < m; ++i) {
    sum.upd(e[i].second+1, mod - vk[e[i].second]);
    cnt.upd(e[i].second+1, mod - 1);
  }
  if (ret < 0) ret += mod;
  return ret;
}
void centroid(int v) {
  get_sz(v);
  int tot = sz[v];
  while (bg[v] != -1 && sz[bg[v]] * 2 >= tot) v = bg[v];
  all.clear();
  for (auto it : g[v]) {
    int u = it.first;
    if (!live[u]) continue;
    s.clear();
    get_m(u, v, it.second, it.second);
    all.insert(all.begin(), s.begin(), s.end());
    ans -= calc(s);
    ans %= mod;
    if (ans < 0) ans += mod;
  }
  ans += calc(all);
  ans %= mod;
  if (ans < 0) ans += mod;
  if (ans > mod) ans -= mod;
  for (auto it : all) {
    ans = (ans + vk[it.first] * 1LL * vk[it.second]) % mod;
  }
  live[v] = 0;
  for (auto it : g[v]) {
    int u = it.first;
    if (!live[u]) continue;
    centroid(u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i+1 < n; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edge[i] = make_tuple(u, v, w);
    vk.push_back(w);
  }
  sort(vk.begin(), vk.end());
  vk.erase(unique(vk.begin(), vk.end()), vk.end());
  for (int i = 0; i+1 < n; ++i) {
    int u, v, w;
    tie(u, v, w) = edge[i];
    w = lower_bound(vk.begin(), vk.end(), w) - vk.begin();
    edge[i] = make_tuple(u, v, w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  ans = 0;
  fill(live, live+n, 1);
  centroid(0);
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}