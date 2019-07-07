#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 6, OF = N / 2;

int maks[N << 2], lazy[N << 2];

void build(int id = 1, int l = 0, int r = N) {
  maks[id] = 0;
  lazy[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, int v) {
  maks[id] += v;
  lazy[id] += v;
}

inline void push(int id, int il, int ir) {
  if (lazy[id] == 0) return;
  upd(il, lazy[id]);
  upd(ir, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = N) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  maks[id] = max(maks[il], maks[ir]);
}

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<tuple<int, int, int, int>> events;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    int l = x - y - d + OF, r = x - y + d + OF + 1;
    int up = x + y - d, down = x + y + d + 1;
    events.emplace_back(up, +1, l, r);
    events.emplace_back(down, -1, l, r);
  }
  build();
  sort(events.begin(), events.end());
  int ans = 0;
  for (auto it : events) {
    int l, r, v;
    tie(ignore, v, l, r) = it;
    update(l, r, v);
    ans = max(ans, maks[1]);
  }
  printf("%d\n", ans);
  return 0;
}
