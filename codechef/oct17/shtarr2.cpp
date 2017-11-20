#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 8;

typedef struct item * pitem;

struct item {
  pitem l, r;
  int x, y, prior, cnt;
  item(int prior, int x, int y) : prior(prior), x(x), y(y), cnt(1), l(NULL), r(NULL) {}
};

int cnt(pitem t) {
  return t ? t->cnt : 0;
}

void upd_cnt(pitem t) {
  if (!t) return;
  t->cnt = cnt(t->l) + 1 + cnt(t->r);
}

void merge(pitem & t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd_cnt(t);
}

void splitx(pitem t, pitem &l, pitem &r, int x) {
  if (!t)
    return void(l = r = NULL);
  if (t->x < x)
    splitx(t->r, t->r, r, x), l = t;
  else
    splitx(t->l, l, t->l, x), r = t;
  upd_cnt(t);
}

void splity(pitem t, pitem &l, pitem &r, int y) {
  if (!t)
    return void(l = r = NULL);
  if (t->y < y)
    splity(t->r, t->r, r, y), l = t;
  else
    splity(t->l, l, t->l, y), r = t;
  upd_cnt(t);
}
int maxy(pitem t) {
  return t ? max(t->y, maxy(t->r)) : -1;
}
int miny(pitem t) {
  return t ? min(t->y, miny(t->l)) : inf;
}

void debug(pitem t) {
  if (!t)
    return;
  debug(t->l);
  cerr << " " << t->x;
  debug(t->r);
}

const int N = 1e6 + 6;
pitem seg[N << 2];
int a[N], n;
void build(int id = 1, int l = 0, int r = n) {
  seg[id] = NULL;
  int last = -1;
  for (int i = l; i < r; i++) {
    if (a[i] <= last) continue;
    last = a[i];
    merge(seg[id], seg[id], new item(rand(), i, a[i]));
  }
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  pitem le, mi, ri;
  splitx(seg[id], le, mi, x);
  splity(mi, mi, ri, a[x]+v+1);
  if (maxy(le) < a[x] + v)
    merge(le, le, new item(rand(), x, a[x]+v));
  merge(seg[id], le, ri);
  if (r-l < 2) {
    a[x] += v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
}

pair<int, int> get(int x, int lo, int hi, int id = 1, int l = 0, int r = n) {
  if (x >= r)
    return make_pair(0, -1);
  if (x <= l) {
    pitem le, mid, ri;
    splity(seg[id], le, mid, lo);
    splity(mid, mid, ri, hi);
    int sum = cnt(mid);
    int ma = maxy(mid);
    if (ri)
      sum++, ma = max(ma, miny(ri));
    merge(mid, mid, ri);
    merge(seg[id], le, mid);
    return make_pair(sum, ma);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  auto ret = get(x, lo, hi, il, l, mid);
  if (ret.second >= hi)
    return ret;
  auto ret2 = get(x, max(lo, ret.second+1), hi, ir, mid, r);
  ret.first += ret2.first;
  ret.second = max(ret.second, ret2.second);
  return ret;
} 


int main() {
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    build();
    for (int i = 0; i < q; i++) {
      char cmd;
      int x, y, z;
      scanf(" %c %d %d", &cmd, &x, &y);
      x--;
      if (cmd == '+')
        update(x, y);
      else {
        scanf("%d", &z);
        printf("%d\n", get(x, y, z).first);
      }
    }
  }
  return 0;
}