#include <bits/stdc++.h>

using namespace std;

struct fenwick {
  vector<int> bit;
  fenwick(int _n) : bit(_n+1, 0) {}
  void reset() {
    fill(bit.begin(), bit.end(), 0);
  }
  void update(int x, int v) {
    for (++x; x < (int)bit.size(); x += x&-x)
      bit[x] += v;
  }
  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    p[i] = {x, i};
  }
  sort(p.begin(), p.end());
  fenwick fen(n);
  vector<int> l(q), r(q), low(q), hig(q);
  vector<vector<int>> que(n+1);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    l[i] -= 2;
    --r[i];
    low[i] = 0;
    hig[i] = r[i] - l[i];
    que[(hig[i] + low[i] + 1) >> 1].push_back(i);
  }
  bool ok = true;
  while (ok) {
    ok = false;
    fen.reset();
    auto it = p.rbegin();
    for (int i = n; i >= 0; --i) {
      while (it != p.rend() && it->first >= i) {
        fen.update(it->second, +1);
        ++it;
      }
      for (auto id : que[i]) {
        int res = fen.get(r[id]) - fen.get(l[id]);
        if (res >= i)
          low[id] = i;
        else
          hig[id] = i - 1;
        if (low[id] < hig[id]) {
          que[(low[id] + hig[id] + 1) >> 1].emplace_back(id);
          ok = true;
        }
      }
      que[i].clear();
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", low[i]);
  return 0;
}
