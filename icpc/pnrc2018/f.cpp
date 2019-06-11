#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> vx, vy;

int sum[N << 2];
bool lazy[N << 2];
void build(int id = 1, int l = 0, int r = vx.size()) {
  sum[id] = lazy[id] = 0;
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void toggle(int id, int l, int r) {
  sum[id] = vx[r] - vx[l] - sum[id];
  lazy[id] ^= 1;
}

void propagate(int id, int l, int r) {
  if (!lazy[id]) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  toggle(il, l, mid);
  toggle(ir, mid, r);
  lazy[id] = 0;
}

void update(int x, int y, int id = 1, int l = 0, int r = vx.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    toggle(id, l, r);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  propagate(id, l, r);
  update(x, y, il, l, mid);
  update(x, y, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

int main() {
  int n;
  scanf("%d", &n);
  vector<tuple<int,int,int,int> > rects;
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    if (xa > xb)
      swap(xa, xb);
    if (ya > yb)
      swap(ya, yb);
    vx.push_back(xa);
    vx.push_back(xb);
    vy.push_back(ya);
    vy.push_back(yb);
    rects.emplace_back(xa, ya, xb, yb);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  vector<tuple<int, int, int>> events;
  for (auto & it : rects) {
    int xa, ya, xb, yb;
    tie(xa, ya, xb, yb) = it;
    xa = lower_bound(vx.begin(), vx.end(), xa) - vx.begin();
    xb = lower_bound(vx.begin(), vx.end(), xb) - vx.begin();
    ya = lower_bound(vy.begin(), vy.end(), ya) - vy.begin();
    yb = lower_bound(vy.begin(), vy.end(), yb) - vy.begin();
    events.emplace_back(ya, xa, xb);
    events.emplace_back(yb, xa, xb);
  }
  sort(events.begin(), events.end());
  build();
  int last = 0;
  long long ans = 0;
  for (auto e : events) {
    int cur, l, r;
    tie(cur, l, r) = e;
    if (last < cur) {
      ans += 1LL * (vy[cur] - vy[last]) * sum[1];
    }
    last = cur;
    update(l, r);
  }
  printf("%lld\n", ans);
  return 0;
}
