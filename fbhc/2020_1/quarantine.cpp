#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> safe;

struct Dsu {
  vector<int> p;
  Dsu(int _n) {
    p.assign(_n, -1);
  }

  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

vector<int> sz, val;

long long dfs1(int v, int par, int totval, int totsz) {
  sz[v] = 1;
  val[v] = safe[v];
  long long ret = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs1(u, v, totval, totsz);
    sz[v] += sz[u];
    val[v] += val[u];
    if (safe[v] && safe[u]) {
      ret += 1LL * (totval - val[u]) * val[u];
    } else {
      ret += 1LL * (totsz - sz[u]) * sz[u];
    }
  }
  return ret;
}

long long dfs2(int v, int par, int totval) {
  long long ret = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs2(u, v, totval);
    val[v] += val[u];
    int cnt = (totval - val[u]);
    if (!safe[v] || !safe[u])
      ret += 1LL * cnt * val[u];
  }
  return ret;
}

long long dfs3(int v, int par) {
  long long ret = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs3(u, v);
    val[v] += val[u];
    if (!safe[u] || !safe[v])
      ret += val[u];
  }
  return ret;
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  g.resize(n);
  for (int i = 0; i < n; ++i)
    g[i].clear();
  string s;
  cin >> s;
  safe.resize(n);
  for (int i = 0; i < n; ++i) {
    safe[i] = s[i] != '#';
  }
  vector<int> e;
  for (int i = 1; i <= k; ++i) {
    int p;
    scanf("%d", &p);
    e.push_back(p);
  }
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  for (int i = k+1; i < n; ++i) {
    e.push_back(((a * e[i-3] + b * e[i-2] + c) % i) + 1);
  }
  Dsu dsu(n);
  val.resize(n);
  sz.resize(n);
  for (int i = 1; i < n; ++i) {
    int p = e[i-1] - 1;
    g[p].push_back(i);
    g[i].push_back(p);
    if (safe[i] && safe[p])
      dsu.merge(i, p);
  }
  vector<pair<int, int>> comp;
  for (int i = 0; i < n; ++i) {
    if (!safe[i]) continue;
    if (dsu.find(i) != i) continue;
    comp.emplace_back(-dsu.p[i], i);
  }
  if (comp.size() <= 1) {
    int root = 0, maxi = 0;
    long long ans1 = 0;
    if (!comp.empty()) {
      maxi = comp[0].first;
      ans1 = comp[0].first;
      ans1 = ans1 * (ans1 - 1) / 2;
      root = comp[0].second;
    }
    long long ans2 = dfs1(root, -1, maxi, n);
    printf("%lld %lld\n", ans1, ans2);
    return;
  }
  sort(comp.begin(), comp.end());
  reverse(comp.begin(), comp.end());
  if (comp[0].first == comp[1].first) {
    int root = -1;
    for (int i = 0; i < n; ++i) {
      if (safe[i]) continue;
      root = i;
      break;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      val[i] = 0;
      if (!safe[i]) continue;
      val[i] = (-dsu.p[dsu.find(i)] == comp[0].first);
      cnt += val[i];
    }
    long long ans2 = dfs2(root, root, cnt);
    long long ans1 = comp[0].first + comp[1].first;
    ans1 = ans1 * (ans1 - 1) / 2;
    for (int i = 2; i < (int)comp.size(); ++i) {
      long long cur = comp[i].first;
      ans1 += cur * (cur - 1) / 2;
    }
    printf("%lld %lld\n", ans1, ans2);
  } else {
    int root = comp[0].second;
    for (int i = 0; i < n; ++i) {
      val[i] = 0;
      if (!safe[i]) continue;
      val[i] = (-dsu.p[dsu.find(i)] == comp[1].first);
    }
    long long ans2 = dfs3(root, root);
    ans2 *= comp[0].first;
    long long ans1 = comp[0].first + comp[1].first;
    ans1 = ans1 * (ans1 - 1) / 2;
    for (int i = 2; i < (int)comp.size(); ++i) {
      long long cur = comp[i].first;
      ans1 += cur * (cur - 1) / 2;
    }
    printf("%lld %lld\n", ans1, ans2);
  }
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
