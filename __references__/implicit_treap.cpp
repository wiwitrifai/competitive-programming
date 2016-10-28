/**
 * Treap uses implicit key
 * This Implementation : maintain array, can insert and delete in any position, can reverse interval 
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;

struct item
{
  int cnt, value, prior;
  bool rev;
  pitem l, r;
  item(int prior, int value) : cnt(1), rev(false), prior(prior), value(value), l(NULL), r(NULL) {}
};

int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd_cnt(pitem it) {
  if (it)
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
  if (it && it->rev) {
    it->rev = false;
    swap(it->l, it->r);
    if (it->l) it->l->rev ^= true;
    if (it->r) it->r->rev ^= true;
  }
}

void merge(pitem & t, pitem l, pitem r) {
  push(l);
  push(r);
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

void reverse(pitem t, int l, int r) {
  pitem t1, t2, t3;
  split(t, t1, t2, l);
  split(t2, t2, t3, r-l+1);
  t2->rev ^= true;
  merge(t, t1, t2);
  merge(t, t, t3);
}
void output (pitem t) {
  if (!t)  return;
  push (t);
  output (t->l);
  printf ("%d ", t->value);
  output (t->r);
}

int main() {
  int n;
  scanf("%d", &n);
  srand(time(NULL));
  pitem root = NULL;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    pitem cur =  new item(rand(), a);
    if (root)
      merge(root, root, cur);
    else
      root = cur;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    reverse(root, l, r);
    output(root);
    printf("\n");
  }
  return 0;
} 