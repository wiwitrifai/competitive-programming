#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

struct seg_tree {
  private:
    int n;
    vector< int > a, init;
    seg_tree(int n, const vector< int > init) : n(n), init(init) {
      a.resize(n << 2);
      build(1, 0, n);
    }
    void build(int id, int l, int r) {
      if(r-l < 2) {
        a[id] = init[l];
        return;
      }
      int mid = (l+r) >> 1, il = id<<1, ir = il | 1;
      build(il, l, mid);
      build(ir, mid, r);
      a[id] = min(a[il], a[ir]);
    }
    void set(int d, int x, int id, int l, int r) {
      if(r-l < 2) {
        a[id] = x;
        init[l] = x;
        return 0;
      }
      int mid = (l+r) >> 1, il = id<<1, ir = il | 1;
      if(d < mid)
        set(d, x, il, l, mid);
      else
        set(d, x, ir, mid, r);
      a[id] = min(a[il], a[ir]);
    }
    int get(int x, int y, int id, int l, int r) {
      if(x >= r || l >= y) return inf;
      if(x <= l && y <= r) return a[id];
      int mid = (l+r) >> 1, il = id<<1, ir = il | 1;
      return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
    }
};

int main() {

  return 0;
}