#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

struct SegTree {
  int n;
  vector<long long> mini;
  SegTree(int _n) : n(_n) {
    mini.assign(2 * n, inf);
  }

  void update(int pos, long long val, int id, int l, int r) {
    mini[id] = min(mini[id], val);
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    if (pos < mid)
      update(pos, val, il, l, mid);
    else
      update(pos, val, ir, mid, r);
  }

  void update(int pos, long long val) {
    update(pos, val, 0, 0, n);
  }

  long long get(int lef, int rig, int id, int l, int r) {
    if (lef >= r || l >= rig) return inf;
    if (lef <= l && r <= rig) return mini[id];
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    return min(get(lef, rig, il, l, mid), get(lef, rig, ir, mid, r));
  }

  long long get(int lef, int rig) {
    return get(lef, rig, 0, 0, n);
  }

};

void solve() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  --a, --b;
  vector<int> p(n), c(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i], &c[i]);
    --p[i];
    if (p[i] >= 0) {
      g[p[i]].push_back(i);
      g[i].push_back(p[i]);
    }
  }

  vector<int> nodes;
  function<bool(int, int)> dfs = [&](int v, int par) {
    nodes.push_back(v);
    if (v == b)
      return true;
    for (int u : g[v]) {
      if (u == par) continue;
      if (dfs(u, v))
        return true;
    }
    nodes.pop_back();
    return false;
  };
  dfs(a, a);
  vector<bool> used(n, false);
  for (int x : nodes)
    used[x] = true;
  vector<int> cheapest;
  function<void(int, int, int)> find = [&](int v, int par, int depth) {
    if (c[v]) {
      if ((int)cheapest.size() <= depth)
        cheapest.resize(depth + 1, 0);
      if (cheapest[depth] == 0 || cheapest[depth] > c[v]) {
        cheapest[depth] = c[v];
      }
    }
    for (int u : g[v]) {
      if (u == par || used[u]) continue;
      find(u, v, depth+1);
    }
  };
  nodes.pop_back();
  SegTree segtree(n+m);
  int offset = 0;
  segtree.update(offset+m, 0);
  for (int x : nodes) {
    cheapest.clear();
    find(x, x, 0);
    for (int i = 0; i < (int)cheapest.size(); ++i) {
      int rest = m - i;
      if (rest < 0) break;
      if (cheapest[i] == 0) continue;
      long long cur = segtree.get(offset+i, offset+m+1) + cheapest[i];
      segtree.update(offset+rest, cur);
    }
    ++offset;
  }
  long long ans = segtree.get(offset, offset+m+1);
  if (ans >= inf)
    ans = -1;
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
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
