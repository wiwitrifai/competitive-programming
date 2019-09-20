#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long inf = 1e18;

struct point {
  int x, y, c;
  point(int _x = 0, int _y = 0, int _c = 0) : x(_x), y(_y), c(_c) {}
  bool operator==(point & p) const {
    return x == p.x && y == p.y;
  }
  bool operator<(point & p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
};

point points[N];
int n;
vector<int> vx;
struct Node {
  long long maxi = 0, lazy = 0;
  int from = -1;
  Node(long long maxi = 0, int from = -1) : maxi(maxi), lazy(0), from(from) {}
};
Node seg[N << 2];

Node max(Node a, Node b) {
  return a.maxi > b.maxi ? a : b;
}


void build(int id = 1, int l = 0, int r = vx.size()) {
  if (r-l < 2) {
    seg[id] = Node(vx[l], vx[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);
  seg[id].lazy = 0;
}

inline void upd(int id, long long c) {
  if (c == 0)
    return;
  seg[id].maxi += c;
  seg[id].lazy += c;
}

inline void push(int id, int il, int ir) {
  if (seg[id].lazy == 0) return;
  upd(il, seg[id].lazy);
  upd(ir, seg[id].lazy);
  seg[id].lazy = 0;
}

void update(int x, int y, int c, int id = 1, int l = 0, int r = vx.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, c);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, c, il, l, mid);
  update(x, y, c, ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);
  seg[id].lazy = 0;
}

Node get(int x, int y, int id = 1, int l = 0, int r = vx.size()) {
  if (x >= r || l >= y) return Node(-inf, -1);
  if (x <= l && r <= y) {
    return seg[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    if (x < y)
      swap(x, y);
    vx.push_back(y);
    points[i] = point(x, y, c);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  long long ans = 0;
  int xa = vx.back() + 1, xb = vx.back() + 1;
  sort(points, points+n);
  auto get_pos = [&](int x)->int {
    return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
  };
  build();
  for (int i = 0; i < n;) {
    int lastx = points[i].x;
    while (i < n && points[i].x == lastx) {
      update(0, get_pos(points[i].y) + 1, points[i].c);
      ++i;
    }
    int r = get_pos(lastx);
    if (r < vx.size() && vx[r] == lastx) ++r;
    Node res = get(0, r);
    res.maxi -= lastx;
    if (ans < res.maxi) {
      ans = res.maxi;
      xa = res.from;
      xb = lastx;
    }
  }
  printf("%lld\n%d %d %d %d\n", ans, xa, xa, xb, xb);
  return 0;
}
