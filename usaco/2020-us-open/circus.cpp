// Still WA (score = 0)
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct Dsu {
  int p[N];
  Dsu() {
    reset();
  }

  void reset() {
    fill(p, p+N, -2);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  int size(int x) {
    return -p[find(x)]-1;
  }
  long long merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return 1;
    long long ret = fac[-p[u]-1] * fac[-p[v]-1] % mod;
    if (p[u] < p[v])
      swap(u, v);
    p[v] += p[u]+1;
    p[u] = v;
    return ret * inv[-p[v]-1] % mod;
  }
};

vector<int> order;
vector<pair<int, int>> merged[N];
int n;
vector<int> g[N];
int in[N], out[N], parent[N];

vector<int> answer() {
  vector<int> ans;
  Dsu dsu;
  long long tot = fac[n];
  for (int i = n-1; i >= 0; --i) {
    ans.push_back(tot);
    for (auto it : merged[i+1]) {
      tot = tot * dsu.merge(it.first, it.second) % mod;
    }
    int v = dsu.find(order[i]);
    ++dsu.p[v];
    tot = tot * -dsu.p[v] % mod;
    tot = tot * powmod(i+1, mod-2) % mod;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void dfs(int v, int par = -1) {
  parent[v] = par == -1 ? v : par;
  in[v] = order.size();
  order.push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
  }
  out[v] = order.size();
}

bool die[N];
int sz[N];

void get_sz(int v, int par) {
  sz[v] = !die[v];
  for (int u : g[v]) {
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
  }
}

int calc(int v, int par) {
  if (g[v].size() > 2) return 2;
  for (int u : g[v]) {
    if (u == par) continue;
    int res = calc(u, v);
    return (res == -1) ? res : res + 1;
  }
  return -1;
}

bool cek(int u, int v) {
  get_sz(u, v);
  if (sz[u] < 2) return false;
  int cnt = 0, w = -1;
  for (int x : g[u]) {
    if (x == v) continue;
    cnt += sz[x] > 0;
    if (sz[x] > 0)
      w = x;
  }
  if (cnt >= 2)
    return true;
  assert(w != -1);
  if (g[u].size() > 2) {
    get_sz(v, u);
    if (sz[v] > 0)
      return true;
  }
  int res = calc(w, u);
  if (res == -1) return false;
  return sz[w] >= res+1;
}

int find(int u, int v) {
  memset(die, false, sizeof die);
  int now = 0;
  while (now < n && (!die[u] || !die[v])) {
    die[order[now++]] = true;
  }
  // cerr << " find  " << u << " " << v << endl;
  while (now < n) {
    // cerr << " " << now << " " << cek(u, v) << " " << cek(v, u) << endl;
    if (!cek(u, v) && !cek(v, u)) {
      return now;
    }
    die[order[now++]] = true;
  }
  return now;
}

void construct() {
  for (int v : order) {
    cerr << v << " , ";
  }
  cerr << endl;
  for (int v = 1; v < n; ++v) {
    int u = parent[v];
    int res = find(u, v);
    merged[res].emplace_back(u, v);
    cerr << u << " " << v << " " << res << endl;
  }
}


int main() {
  const string prob = "circus";
  freopen((prob + ".in").c_str(), "r", stdin);
  freopen((prob + ".out").c_str(), "w", stdout);

  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  construct();
  vector<int> ans = answer();
  for (int x : ans) {
    printf("%d\n", x);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
