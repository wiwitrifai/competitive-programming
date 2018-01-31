#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int pos[N << 2], len = 1e5 + 1;

void build(int id = 1, int l = 0, int r = len) {
  if (r-l < 2) {
    pos[id] = l;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  pos[id] = 0;
}

void push(int id) {
  if (pos[id]) {
    int il = id << 1, ir = il | 1;
    pos[il] = pos[id];
    pos[ir] = pos[id];
    pos[id] = 0;
  }
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = len) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    pos[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
}

int get(int x, int id = 1, int l = 0, int r = len) {
  if (r-l < 2)
    return pos[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (x < mid)
    return get(x, il, l, mid);
  else
    return get(x, ir, mid, r);
}

int main() {
  vector<tuple<int, int, int> > segments;
  build();
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    segments.emplace_back(c, a, b);
  }
  sort(segments.begin(), segments.end());
  for (int i = 0; i < n; ++i) {
    int l, r;
    tie(ignore, l, r) = segments[i];
    int le = get(l), ri = get(r);
    int mid = (l + r) >> 1;
    update(l, mid+1, le);
    if (mid+1 <= r)
      update(mid+1, r, ri);
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", get(x));
  }
  return 0;
}