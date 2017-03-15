#include <bits/stdc++.h>

using namespace std;
typedef struct item * pitem;
struct item
{
  int prior, key, cnt;
  pitem l, r;
  item() {}
  item(int key, int prior) : cnt(1), key(key), prior(prior), l(NULL), r(NULL) {}
};
int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
  }
}
void split(pitem t, int key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (t->key < key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, t->l), r = t;
  upd_cnt(l);
  upd_cnt(r);
}
void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r; 
  upd_cnt(t); 
}
void insert(pitem & t, pitem  it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(t->key > it->key ? t->l : t->r, it);
  upd_cnt(t);
}
void erase(pitem &t, int key) {
  if (!t)
    return;
  else if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
  upd_cnt(t);
}

void print(pitem t) {
  if (!t) return;
  printf("%d\n", t->key);
  printf("%d kiri\n", t->key);
  print(t->l);
  printf("%d kanan\n", t->key);
  print(t->r);
}

pitem unite(pitem l, pitem r) {
  if (!l || !r)
    return l ? l : r;
  if (l->prior < r->prior)
    swap(l, r);
  pitem t1, t2;
  split(r, l->key, t1, t2);
  l->l = unite(l->l, t1);
  l->r = unite(l->r, t2); 
  return l;
}

int get(pitem & t, int key) {
  if (!t)
    return 0;
  else if (t->key == key)
    return 0;
  else if (t->key > key)
    return get(t->l, key);
  else
    return cnt(t->l) + 1 + get(t->r, key);
}

const int N = 2e5 + 5;
pitem seg[N << 2];
int n, a[N];
void build(int id = 1, int l = 0, int r = n) {
  seg[id] = NULL;
  for (int i = l; i < r; i++)
    insert(seg[id], new item(i, rand()));
  // cerr << l << " build " << r << endl;
  // print(seg[id]);
  if (r-l < 2) {
    a[l] = l;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void upd(int x, int val, int id = 1, int l = 0, int r = n) {
  erase(seg[id], a[x]);
  insert(seg[id], new item(val, rand()));
  if (r-l < 2) {
    a[x] = val;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd(x, val, il, l, mid);
  else
    upd(x, val, ir, mid, r);
}
int get(int x, int y, int up, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    // print(seg[id]);
    // cerr << l << " " << r << " " << get(seg[id], up) << endl;
    return get(seg[id], up);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(x, y, up, il, l, mid) + get(x, y, up, ir, mid, r);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  build();
  // cerr << get(0, 3, 2) << endl;
  long long ans = 0;
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--, r--;
    if (l > r) swap(l, r);
    if (l != r) {
      int vl = a[l], vr = a[r];
      int cl = get(l+1, r, vl), cr = get(l+1, r, vr);
      int len = r-l + 1;
      ans += 2LL * (cr-cl);
      if (vl < vr)
        ans++;
      else
        ans--;
      upd(l, vr);
      upd(r, vl);
    }
    printf("%lld\n", ans);
  }
  return 0;
}