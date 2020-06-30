#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
  int n;
  vector<int> bit;
  Fenwick(int n_) : n(n_+2), bit(n, 0) {}
  void add(int x, int v) {
    for (++x; x < n; x += x&-x)
      bit[x] += v;
  }
  int get(int x) {
    int r = 0;
    for (++x; x; x -= x&-x)
      r += bit[x];
    return r;
  }
};

int solve() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<int> lef(n), rig(m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &lef[i]);
  for (int i = 0; i < m; ++i)
    scanf("%d", &rig[i]);
  Fenwick bl(n), br(m);
  bl.add(0, +1);
  br.add(0, +1);
  for (int i = 0; i < q; ++i) {
    int la, ra, lb, rb, k, pos;
    scanf("%d %d %d %d %d %d", &la, &ra, &lb, &rb, &k, &pos);
    --pos;
    --la, --lb;
    long long ans = 0;
    if (k == 1) {
      bl.add(la, +1);
      bl.add(ra, -1);
      br.add(lb, -1);
      br.add(rb, +1);
      ans = 1LL * lef[pos] * bl.get(pos);
    } else {
      bl.add(la, -1);
      bl.add(ra, +1);
      br.add(lb, +1);
      br.add(rb, -1);
      ans = 1LL * rig[pos] * br.get(pos);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
