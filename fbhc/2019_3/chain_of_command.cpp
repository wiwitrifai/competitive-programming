#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;

struct BIT {
  int bit[N];
  BIT() {
    memset(bit, 0, sizeof bit);
  }
  void upd(int x, int v) {
    for (++x; x < N; x += x&-x)
      bit[x] += v;
  }
  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }
};

int n, p[N], root, lv[N];
set<int> child[N];

void read_input() {
  scanf("%d", &n);
  root = -1;
  for (int i = 0; i < n; ++i)
    child[i].clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
    if (p[i] < 0)
      root = i;
    else
      child[p[i]].insert(i);
  }
}


int st[N], en[N], cntr = 0;
const int LG = 20, mod = 1e9 + 7;
int par[LG][N];
void dfs(int v, int pp = -1) {
  st[v] = cntr++;
  par[0][v] = pp < 0 ? v : pp;
  lv[v] = pp < 0 ? 0 : lv[pp] + 1;
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : child[v]) {
    dfs(u, v);
  }
  en[v] = cntr;
}

int ancestor(int v, int naik) {
  if (naik < 0)
    return -1;
  for (int i = 0; i < LG; ++i)
    if (naik & (1 << i)) {
      v = par[i][v];
    }
  return v;
}

bool used[N];

int find(int x) {
  if (p[x] < 0) return -1;
  if (child[p[x]].empty())
    return p[x] = find(p[x]);
  if (child[p[x]].size() == 1 && child[p[x]].count(ancestor(x, lv[x] - lv[p[x]]-1)))
    return p[x] = find(p[x]);
  return p[x];
}

void solve() {
  cntr = 0;
  dfs(root);
  BIT up, down;
  long long ans = 1, sum = 0;
  memset(used, false, sizeof used);
  for (int i = 0; i < n; ++i) {
    long long val = up.get(st[i]) + 1;
    down.upd(st[i], +1);
    sum += val;
    int now = i;
    while (now >= 0) {
      int v = ancestor(i, lv[i] - lv[now] - 1);
      bool ada = 0;
      for (int u : child[now]) {
        if (u == v) {
          ada = 1;
          continue;
        }
        sum += down.get(en[u]-1) - down.get(st[u]-1);
        up.upd(st[u], +1);
        up.upd(en[u], -1);
        used[u] = true;
      }
      child[now].clear();
      if (ada)
        child[now].insert(v);
      now = find(now);
    }
    sum %= mod;
    ans = ans * sum % mod;
  }
  printf("%lld\n", ans);
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
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
