#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;

struct item
{
  int cnt, val, prior, best, suml, sumr, sum;
  pitem l, r;
  item(int prior, int value) : cnt(1), prior(prior), val(value), l(NULL), r(NULL) {}
};

int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd(pitem it) {
  if (it) {
    int val = it->val;
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    it->sum = val + (it->l ? it->l->sum : 0) + (it->r ? it->r->sum : 0);
    if (it->l && it->r) {
      it->best = max(it->l->best, it->r->best);
      it->best = max(it->l->sumr + val, it->best);
      it->best = max(it->r->suml + val, it->best);
      it->best = max(it->l->sumr + val + it->r->suml, it->best);
      it->best = max(val, it->best); 
      it->suml = max(it->l->suml, it->l->sum + val + max(it->r->suml, 0));
      it->sumr = max(it->r->sumr, it->r->sum + val + max(it->l->sumr, 0));
    }
    else if (it->l) {
      it->best = max(it->l->best, max(it->l->sumr, 0)+val);
      it->suml = max(it->l->suml, it->l->sum + val);
      it->sumr = it->val + max(it->l->sumr, 0);
    }
    else if (it->r) {
      it->best = max(it->r->best, max(it->r->suml, 0)+val);
      it->sumr = max(it->r->sumr, it->r->sum + val);
      it->suml = it->val + max(it->r->suml, 0);
    }
    else {
      it->best = it->suml = it->sumr = val;
    }
  }
}

void merge(pitem & t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd(t);
}

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void (l = r = 0);
  int cur_key = cnt(t->l) + add;
  if (key <= cur_key)
    split(t->l, l, t->l, key, add), r = t;
  else
    split(t->r, t->r, r, key, add + cnt(t->l) + 1), l = t;
  upd(t);
}
void insert(pitem &t, int key, pitem it) {
  pitem l, r;
  split(t, l, r, key);
  merge(t, l, it);
  merge(t, t, r);
}
void erase(pitem &t, int key, int add = 0) {
  if (!t)
    return;
  int cur_key = cnt(t->l) + add;
  if (key == cur_key) {
    merge(t, t->l, t->r);
  }
  else if (key < cur_key)
    erase(t->l, key, add);
  else
    erase(t->r, key, add + 1 + cnt(t->l));
  upd(t);
}
void replace(pitem &t, int key, int val, int add = 0) {
  if (!t)
    return;
  int cur_key = cnt(t->l) + add;
  if (cur_key == key)
    t->val = val;
  else if (key < cur_key)
    replace(t->l, key, val, add);
  else
    replace(t->r, key, val, add + cnt(t->l) + 1);
  upd(t);
}

void output(pitem t) {
  if (!t)
    return;
  output(t->l);
  printf("%d ", t->val);
  output(t->r);
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
    char s[5];
    int x, y;
    scanf("%s %d", s, &x);
    x--;
    if (s[0] != 'D')
      scanf("%d", &y);
    if (s[0] == 'I') {
      pitem cur = new item(rand(), y);
      upd(cur);
      insert(root, x, cur);
    }
    else if (s[0] == 'D')
      erase(root, x);
    else if (s[0] == 'R')
      replace(root, x, y);
    else {
      pitem t1, t2, t3;
      split(root, t1, t2, x);
      split(t2, t2, t3, y-x);
      printf("%d\n", t2->best);
      merge(root, t1, t2);
      merge(root, root, t3);
    }
  }
  return 0;
} 