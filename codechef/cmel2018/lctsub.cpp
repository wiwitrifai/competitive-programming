#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

struct node {
  node * l, * r;
  int val, lz;
  node() : l(NULL), r(NULL), val(0), lz(0) {
  }
  node * getR() {
    if (!r)
      r = new node();
    return r;
  }
  node * getL() {
    if (!l)
      l = new node();
    return l;
  }
  void push() {
    if (lz == 0) return;
    if (l) {
      l->val = max(l->val, lz);
      l->lz = max(l->lz, lz);
    }
    if (r) {
      r->val = max(r->val, lz);
      r->lz = max(r->lz, lz);
    }
    lz = 0;
  }
  void pull() {
    val = 0;
    if (l) val = max(val, l->val);
    if (r) val = max(val, r->val);
  }
};

int get(node * t, int x, int y, int l = 0, int r = inf) {
  if (!t) return 0;
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return t->val;
  int mid = (l + r) >> 1;
  t->push();
  return max(get(t->l, x, y, l, mid), get(t->r, x, y, mid, r));
}

void upd(node * t, int x, int y, int z, int l = 0, int r = inf) {
  if (!t) return;
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    t->val = max(t->val, z);
    t->lz = max(t->lz, z);
    return;
  }
  int mid = (l + r) >> 1;
  t->push();
  upd(t->getL(), x, y, z, l, mid);
  upd(t->getR(), x, y, z, mid, r);
  t->pull();
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    int n;
    node * root = new node();
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int a, l;
      scanf("%d %d", &a, &l);
      a ^= ans;
      l ^= ans;
      int le = a-l, ri = a+l+1;
      le = max(le, 0);
      ri = min(ri, inf);
      int cur = get(root, le, ri);
      upd(root, a, a+1, cur+1);
      ans = max(ans, cur+1);
      printf("%d\n", ans);
    }
  }
  return 0;
}