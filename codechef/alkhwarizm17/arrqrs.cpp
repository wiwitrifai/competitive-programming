#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

typedef struct item * pitem;

struct item
{
  int cnt, value, prior, mi;
  pitem l, r;
  item(int prior, int value) : cnt(1), prior(prior), value(value), mi(value), l(NULL), r(NULL) {}
};

int cnt(pitem t) {
  return t ? t->cnt : 0;
}
int mi(pitem t) {
  return t ? t->mi : inf;
}
void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    it->mi = min(value, min(mi(it->l), mi(it->r)));
  }
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

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void (l = r = 0);
  int cur_key = cnt(t->l) + add;
  if (key <= cur_key)
    split(t->l, l, t->l, key, add), r = t;
  else
    split(t->r, t->r, r, key, add + cnt(t->l) + 1), l = t;
  upd_cnt(t);
}

void output (pitem t) {
  if (!t)  return;
  push (t);
  output (t->l);
  printf ("%d ", t->value);
  output (t->r);
}


int main() {
  srand(time(0));
  pitem root = NULL;
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1)
      merge(root, root, new item(rand(), x));
    else if (t == 2) {
      pitem s1, s2;
      split(root, s1, root, x-1);
      split(root, s2, root, 1);
      merge(root, s1, root);
    }
    else if (t == 3) {
      int z;
      scanf("%d", &z);
      pitem s1, s2;
      split(root, s1, root, x-1);
      split(root, s2, root, 1);
      merge(root, new item(rand(), z), root);
      merge(root, s1, root);
    }
    else {
      
    }
  }
  return 0;
}