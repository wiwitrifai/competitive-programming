#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct Node {
  int maxi, lazy;
  Node(int maxi = 0, int lazy = 0) : maxi(maxi), lazy(lazy) {}

  void upd(int v) {
    maxi += v;
    lazy += v;
  }
  void assign(int v) {
    maxi = v;
    lazy = 0;
  }
  void push(Node & le, Node & ri) {
    if (lazy == 0) return;
    le.upd(lazy);
    ri.upd(lazy);
    lazy = 0;
  }
  void combine(Node & le, Node & ri) {
    maxi = max(le.maxi, ri.maxi);
    lazy = 0;
  }
};

Node seg[N << 2];
int n;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    seg[id].upd(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  seg[id].push(seg[il], seg[ir]);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

void assign(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].assign(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  seg[id].push(seg[il], seg[ir]);
  if (x < mid)
    assign(x, v, il, l, mid);
  else
    assign(x, v, ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return seg[id].maxi;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  seg[id].push(seg[il], seg[ir]);
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int p[N+N];
int lef[N], rig[N], pos[N], startr[N];

int main() {
  scanf("%d", &n);
  int offset = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
    if (p[i] == 0)
      offset = i;
  }
  for (int i = 0; i < n; ++i)
    p[i+n] = p[i];
  for (int i = 0; i < n; ++i) {
    p[i] = p[i+offset];
    pos[p[i]] = i;
  }
  p[n] = 1;
  stack<int> decr;
  for (int i = 0; i < n; ++i) {
    while (!decr.empty() && p[decr.top()] >= p[i])
      decr.pop();
    lef[i] = decr.empty() ? 0 : decr.top() + 1;
    decr.push(i);
  }
  while (!decr.empty()) decr.pop();
  for (int i = n; i > 0; --i) {
    while (!decr.empty() && p[decr.top()] >= p[i])
      decr.pop();
    rig[i] = decr.empty() ? n : decr.top() - 1;
    decr.push(i);
  }
  update(1, n, +1);
  for (int i = 1; i < n; ++i) {
    update(i+1, rig[i]+1, +1);
    startr[i] = get(i, i+1);
    update(lef[i], i, +1);
  }
  int ans = seg[1].maxi, ansoff = 0;
  for (int i = 1; i < n; ++i) {
    update(i+1, rig[i]+1, -1);
    assign(i, startr[i]);
    update(lef[i], i, +1);
    if (seg[1].maxi < ans) {
      ans = seg[1].maxi;
      ansoff = i+1;
    }
  }
  ansoff = (ansoff + offset) % n;
  printf("%d %d\n", ans+1, ansoff);
  return 0;
}
