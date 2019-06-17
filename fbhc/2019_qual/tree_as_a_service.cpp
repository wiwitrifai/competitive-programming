#include <bits/stdc++.h>

using namespace std;

const int N = 212;

long long anc[N];
int x[N], y[N], z[N];
long long par[N];
vector<int> cons[N];
int used[N];

vector<int> g[N];
int lv[N];

bool dfs(int v, int depth = 0) {
  if (lv[v] != -1) return false;
  lv[v] = depth;
  for (int u : g[v]) {
    if (!dfs(u, depth + 1))
      return false;
  }
  return true;
}

int lca(int u, int v) {
  while (u != v) {
    if (lv[u] > lv[v])
      u = par[u];
    else
      v = par[v];
  }
  return v;
}

int n, m;
vector<pair<long long *, long long> > logs;

void assign(long long * var, long long val) {
  if (*var == val)
    return;
  logs.emplace_back(var, *var);
  *var = val;
}

void apply() {
  queue<int> que;
  for (int i = 1; i <= n; ++i)
    que.push(i);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    bool repeat = 1;
    while (repeat) {
      repeat = 0;
      for (int i = 1; i <= n; ++i) {
        if ((anc[v] >> i) & 1) {
          long long res = anc[v] | anc[i];
          if (res == anc[v]) continue;
          assign(&anc[v], res);
          repeat = 1;
        }
      }
    }
    for (int c : cons[v]) {
      int a = x[c], b = y[c], w = z[c];
      long long common = anc[a] & anc[b];
      if (w != b && w != a && (common & anc[w]) != common) {
        assign(&anc[w], anc[w] | common);
        que.push(w);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if ((anc[i] >> v) & 1) {
        long long res = anc[i] | anc[v];
        if (res == anc[i]) continue;
        assign(&anc[i], res);
        que.push(i);
      }
    }
  }
}

bool check() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (((anc[i] >> j) & 1) && ((anc[j] >> i) & 1))
        return false;
    }
  }
  for (int i = 0; i < m; ++i) {
    int a = x[i], b = y[i], w = z[i];
    if (a == w || b == w || used[w]) continue;
    while (par[a]) a = par[a];
    while (par[b]) b = par[b];
    if (a == b)
      return false;
  }
  return true;
}

void revert(int sz) {
  if ((int)logs.size() <= sz)
    return;
  for (int i = (int)logs.size()-1; i >= sz; --i) {
    *logs[i].first = logs[i].second;
  }
  logs.resize(sz);
}

void debug() {
  for (int i = 1; i <= n; ++i) {
    cerr << i << " :\t";
    for (int j = 1; j <= n; ++j) {
      cerr << ((anc[i] >> j) & 1);
    }
    cerr << endl;
  }
}

bool find_valid() {
  logs.clear();
  memset(par, 0, sizeof par);
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; ++i)
    anc[i] = 1LL << i;
  for (int i = 1; i <= n; ++i)
    cons[i].clear();
  for (int i = 0; i < m; ++i) {
    cons[z[i]].push_back(i);
    cons[x[i]].push_back(i);
    cons[y[i]].push_back(i);
    anc[x[i]] |= 1LL << z[i];
    anc[y[i]] |= 1LL << z[i];
  }
  apply();
  if (!check()) {
    return false;
  }
  long long unused = 0;
  for (int i = 1; i <= n; ++i) {
    unused |= 1LL << i;
  }
  vector<int> nodes;
  for (int i = 1; i <= n; ++i)
    nodes.push_back(i);
  for (int i = 1; i <= n; ++i) {
    int select = -1;
    int last = logs.size();
    random_shuffle(nodes.begin(), nodes.end());
    for (int x = 0; x < n; ++x) {
      int v = nodes[x];
      if (used[v]) continue;
      used[v] = 1;
      bool ok = 1;
      for (int u = 1; u <= n; ++u) {
        if (u == v) continue;
        if (((anc[u] >> v) & 1) && !used[u]) {
          ok = 0;
        }
      }
      if (!ok) {
        used[v] = 0;
        continue;
      }
      for (int u = 1; u <= n; ++u) {
        if (u == v) continue;
        if (((anc[u] >> v) & 1) && par[u] == 0) {
          assign(&anc[v], anc[v] | (unused & anc[u]));
          assign(&par[u], v);
        }
      }

      apply();

      if(check()) {
        select = v;
        break;
      }
      else {
        used[v] = 0;
        revert(last);
      }
    }
    if (select == -1) {
      return false;
    }
    unused ^= 1LL << select;
  }
  int root = -1;
  for (int i = 1; i <= n; ++i) {
    if (par[i] == 0) {
      if (root == -1)
        root = i;
      else
        par[i] = root;
    }
  }
  for (int i = 1; i <= n; ++i)
    g[i].clear();
  for (int i = 1; i <= n; ++i)
    if (par[i] != 0)
      g[par[i]].push_back(i);
  memset(lv, -1, sizeof lv);
  if (!dfs(root)) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    if (x[i] != z[i] && y[i] != z[i]) {
      assert((anc[x[i]] & anc[y[i]]) == anc[z[i]]);
    }
    assert(lca(x[i], y[i]) == z[i]);
  }
  for (int i = 1; i <= n; ++i)
    printf(" %lld", par[i]);
  printf("\n");
  return true;
}

void solve(int tc) {
  printf("Case #%d:", tc);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", x+i, y+i, z+i);
  }
  int trycount = 200;
  while (trycount--) {
    if (find_valid())
      return;
  }
  puts(" Impossible");
}

int main() {
  srand(time(0));
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
