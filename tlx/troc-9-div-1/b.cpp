#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17 + 7;

struct Node {
  long long lazy, minsuf, maxsuf, minpre, maxpre;
  Node() {
    lazy = 0;
    minpre = minsuf = inf;
    maxpre = maxsuf = -inf;
  }
  Node(long long tlazy, long long tsuf, long long tpre) : lazy(tlazy){
    minsuf = maxsuf = tsuf;
    minpre = maxpre = tpre;
  }
  void upd(int add) {
    lazy += add;
    minsuf += add;
    maxsuf += add;
    minpre += add;
    maxpre += add;
  }
  void push(Node & lef, Node & rig) {
    if (lazy == 0) return;
    lef.upd(lazy);
    rig.upd(lazy);
    lazy = 0;
  }
};

Node seg[N << 2];
int t[N], n;
Node add(Node a, Node b) {
  Node ret;
  ret.minsuf = min(a.minsuf, b.minsuf);
  ret.minpre = min(a.minpre, b.minpre);
  ret.maxsuf = max(a.maxsuf, b.maxsuf);
  ret.maxpre = max(a.maxpre, b.maxpre);
  return ret;
}

void build(int id = 1, int l = 0, int r= n) {
  if (r-l < 2) {
    seg[id] = Node(0, t[l] + l, t[l] - l);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = add(seg[il], seg[ir]);
}

void update(int x, int y, int c, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    seg[id].upd(c);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  seg[id].push(seg[il], seg[ir]);
  update(x, y, c, il, l, mid);
  update(x, y, c, ir, mid, r);
  seg[id] = add(seg[il], seg[ir]);
}
Node get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return Node();
  if (x <= l && r <= y) {
    return seg[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  seg[id].push(seg[il], seg[ir]);
  return add(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", t+i);
  build();
  for (int i = 0; i < q; ++i) {
    int w, x, y, z;
    scanf("%d %d %d %d", &w, &x, &y, &z);
    --x;
    if (w == 1) {
      update(x, y, z);
    }
    else {
      --z;
      long long maxi = -inf;
      long long mini = inf;
      if (x <= z) {
        int l = x, r = min(z+1, y);
        Node res = get(l, r);
        maxi = max(maxi, z + res.maxpre);
        mini = min(mini, z + res.minpre);
      }
      if (z < y) {
        int l = max(z, x), r = y;
        Node res = get(l, r);
        maxi = max(maxi, res.maxsuf - z);
        mini = min(mini, res.minsuf - z);
      }
      printf("%lld\n", maxi - mini);
    }
  }
  return 0;
}
