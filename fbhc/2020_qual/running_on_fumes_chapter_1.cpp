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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }

  SegTree segtree(n+m);
  int offset = 0;
  segtree.update(offset + m, 0);
  for (int i = 0; i < n-1; ++i) {
    if (c[i]) {
      long long cur = segtree.get(offset, offset+m+1) + c[i];
      segtree.update(offset+m, cur);
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
