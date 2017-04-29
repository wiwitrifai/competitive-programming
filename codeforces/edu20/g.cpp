#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7, N = 1e5 + 5;

struct seg_tree {
  int n;
  vector< int > a, mi, lz;
  seg_tree(const vector< int > &v) : a(v) {
    n = a.size();
    mi.resize(n * 4);
    lz.resize(n * 4);
    build(1, 0, n);
  }
  void build(int id, int l, int r) {
    lz[id] = 0;
    if (r-l < 2) {
      mi[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    mi[id] = min(mi[il], mi[ir]);
  }
  void shift(int id) {
    if (lz[id]) {
      int il = id << 1, ir = il | 1;
      mi[il] = lz[il] = mi[ir] = lz[ir] = lz[id];
      lz[id] = 0;
    }
  }
  void upd(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      mi[id] = lz[id] = v;
      return;
    }
    shift(id);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    upd(x, y, v, il, l, mid);
    upd(x, y, v, ir, mid, r);
    mi[id] = min(mi[il], mi[ir]);
  }
  int get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return inf;
    if (x <= l && r <= y) {
      return mi[id];
    }
    shift(id);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
};

vector< int > a;
vector< int > b;
int l[N], r[N];
int t[N], v[N];

int main() {
  a.clear();
  b.clear();
  int n, k, q;
  scanf("%d %d", &n, &k);
  int mall = inf;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x); 
    mall = min(mall, x);
  }
  seg_tree seg(a);
  vector< int > batas;
  batas.push_back(0);
  batas.push_back(n * k);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", t+i, l+i, r+i);
    l[i]--;
    if (t[i] == 1)
      scanf("%d", v+i);
    batas.push_back(l[i]);
    batas.push_back(r[i]);
  }
  sort(batas.begin(), batas.end());
  batas.erase(unique(batas.begin(), batas.end()), batas.end());
  for (int i = 0; i + 1 < batas.size(); i++) {
    int le = batas[i], ri = batas[i+1];
    if (ri-le >= n)
      b.push_back(mall);
    else {
      ri %= n;
      if (ri == 0) ri = n;
      le %= n;
      if (le < ri)
        b.push_back(seg.get(le, ri, 1, 0, n));
      else
        b.push_back(min(seg.get(le, n, 1, 0, n), seg.get(0, ri, 1, 0, n)));
    }
  }
  seg_tree smi(b);
  for (int i = 0; i < q; i++) {
    l[i] = lower_bound(batas.begin(), batas.end(), l[i]) - batas.begin();
    r[i] = lower_bound(batas.begin(), batas.end(), r[i]) - batas.begin();
    assert (l[i] >= 0 && l[i] < b.size());
    assert (r[i] > 0 && r[i] <= b.size());
    assert (l[i] < r[i]);
    if (t[i] == 1)
      smi.upd(l[i], r[i], v[i], 1, 0, b.size());
    else
      printf("%d\n", smi.get(l[i], r[i], 1, 0, b.size()));
  }
  return 0;
}