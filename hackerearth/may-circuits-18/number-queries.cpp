#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18 + 18;

typedef struct item * pitem;
struct item
{
  int prior, cnt;
  long long key, lazy;
  pitem l, r;
  item() {}
  item(long long key_, int prior) : cnt(1), key(key_), prior(prior), l(NULL), r(NULL), lazy(0) {}
};
int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
  }
}
void upd_key(pitem it, long long v) {
  if (!it) return;
  it->key += v;
  it->lazy += v;
}
void push_key(pitem it) {
  if (!it) return;
  if (it->lazy == 0) return;
  upd_key(it->l, it->lazy);
  upd_key(it->r, it->lazy);
  it->lazy = 0;
}
void split(pitem t, long long key, pitem & l, pitem & r) {
  push_key(t);
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
  push_key(l);
  push_key(r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd_cnt(t);
}

void print(pitem t) {
  if (!t) return;
  push_key(t);
  printf("%lld\n", t->key);
  printf("%lld kiri\n", t->key);
  print(t->l);
  printf("%lld kanan\n", t->key);
  print(t->r);
}

pitem unite(pitem l, pitem r) {
  push_key(l);
  push_key(r);
  if (!l || !r)
    return l ? l : r;
  if (l->prior < r->prior)
    swap(l, r);
  pitem t1, t2;
  split(r, l->key, t1, t2);
  l->l = unite(l->l, t1);
  l->r = unite(l->r, t2); 
  upd_cnt(l);
  return l;
}

int get(pitem t, long long key) {
  push_key(t);
  if (!t)
    return 0;
  else if (t->key >= key)
    return get(t->l, key);
  else
    return cnt(t->l) + 1 + get(t->r, key);
}

long long get_key(pitem t, int k) {
  push_key(t);
  if (!t) {
    assert(false);
    return 0;
  }
  if (cnt(t->l) == k)
    return t->key;
  else if (cnt(t->l) > k)
    return get_key(t->l, k);
  else
    return get_key(t->r, k-cnt(t->l)-1);
}

long long a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sort(a, a+n);
  pitem root = NULL;
  srand(time(0));
  for (int i = 0; i < n; ++i)
    merge(root, root, new item(a[i], rand() * rand()));
  for (int i = 0; i < q; ++i) {
    int t;
    long long l, r;
    scanf("%d %lld", &t, &l);
    if (t == 1) {
      pitem p1, p2;
      split(root, l, p1, p2);
      upd_key(p2, -l);
      root = unite(p1, p2);
    }
    else {
      int x;
      scanf("%lld %d", &r, &x);
      int ofs = get(root, l);
      int id = ofs + x - 1;
      long long res = id < n ? get_key(root, id) : inf;
      printf("%lld\n", res <= r ? res : l);
    }
  }
  return 0;
}