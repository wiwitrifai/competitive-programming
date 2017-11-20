#include <bits/stdc++.h>

using namespace std;

const int N = 8192;

struct seg_tree {
  set<int> st[N];
  seg_tree() {
  }
  void add(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      st[id].insert(v);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    add(x, y, v, il, l, mid);
    add(x, y, v, ir, mid, r);
  }
  void rem(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      st[id].erase(v);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    rem(x, y, v, il, l, mid);
    rem(x, y, v, ir, mid, r);
  }
  int get(int x, int id, int l, int r) {
    if (r-l < 2) {
      return st[id].empty() ? 0 : *st[id].rbegin();
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    int ret = st[id].empty() ? 0 : *st[id].rbegin();
    if (x < mid)
      ret = max(ret, get(x, il, l, mid));
    else
      ret = max(ret, get(x, ir, mid, r));
    return ret;
  }
};
int n, m;
seg_tree s[N];
void add(int x, int y, int lo, int hi, int v, int id, int l, int r) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    s[id].add(lo, hi, v, 1, 0, m);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, lo, hi, v, il, l, mid);
  add(x, y, lo, hi, v, ir, mid, r);
}
void rem(int x, int y, int lo, int hi, int v, int id, int l, int r) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    s[id].rem(lo, hi, v, 1, 0, m);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  rem(x, y, lo, hi, v, il, l, mid);
  rem(x, y, lo, hi, v, ir, mid, r);
}
int get(int x, int y, int id, int l, int r) {
  if (r-l < 2)
    return s[id].get(y, 1, 0, m);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int ret = s[id].get(y, 1, 0, m);
  if (x < mid)
    ret = max(ret, get(x, y, il, l, mid));
  else
    ret = max(ret, get(x, y, ir, mid, r));
  return ret;
}

int main() {
  int q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < q; i++) {
    int a, b, c, d, t;
    scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
    a--; b--;
    if (t == 1) {
      add(a, c, b, d, a * m + b + 1, 1, 0, n);
    }
    else if (t == 2) {
      rem(a, c, b, d, a * m + b + 1, 1, 0, n);
    }
    else {
      c--; d--;
      int le = get(a, b, 1, 0, n), ri = get(c, d, 1, 0, n);
      puts(le == ri ? "Yes" : "No");
    }
  }
  return 0;
}