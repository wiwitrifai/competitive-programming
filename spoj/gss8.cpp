#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 11;
unsigned int C[K][K];
typedef struct item * pitem;

struct item {
  unsigned int a[K], val, cnt, prior;
  pitem l, r;
  item(unsigned int prior, unsigned int val) : cnt(1), prior(prior), val(val), l(NULL), r(NULL) {
    for (int i = 0; i < K; i++)
      a[i] = val;
  }
};
unsigned int cnt(pitem t) {
  return t ? t->cnt : 0;
}
void upd(pitem t) {
  if (!t)
    return;
  t->cnt = cnt(t->l) + cnt(t->r) + 1;
  if (t->l && t->r) {
    pitem l = t->l, r = t->r;
    unsigned int mul = 1;
    for (int i = 0; i < K; i++) {
      unsigned int add = 0, ccnt = 1;
      for (int j = i; j >= 0; j--) {
        add += r->a[j] * C[i][j] * ccnt;
        ccnt *= l->cnt+1;
      }
      t->a[i] = l->a[i] + mul * t->val + add;
      mul *= t->l->cnt + 1;
    }
  }
  else if (t->l) {
    unsigned int mul = 1;
    for (int i = 0; i < K; i++) {
      t->a[i] = t->l->a[i] + mul * t->val;
      mul *= t->l->cnt + 1;
    }
  }
  else if (t->r) {
    for (int i = 0; i < K; i++) {
      unsigned int add = 0;
      for (int j = i; j >= 0; j--) {
        add += t->r->a[j] * C[i][j];
      }
      t->a[i] = t->val + add;
    }
  }
  else {
    for (int i = 0; i < K; i++)
      t->a[i] = t->val;
  }
}
void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void(l = r = NULL);
  int cur_key = cnt(t->l) + add;
  if (cur_key < key)
    split(t->r, t->r, r, key, add + cnt(t->l) + 1), l = t;
  else
    split(t->l, l, t->l, key, add), r = t; 
  upd(t);
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
void output(pitem t) {
  if (!t)
    return;
  output(t->l);
  cerr << t->val << " ";
  output(t->r);
}
void replace(pitem &t, int key, int val, int add = 0) {
  if (!t)
    return;
  int cur_key = cnt(t->l) + add;
  if (cur_key == key)
    t->val = val;
  else if (cur_key < key)
    replace(t->r, key, val, add + cnt(t->l) + 1);
  else
    replace(t->l, key, val, add);
  upd(t);
}
void erase(pitem &t, int key, int add = 0) {
  if (!t)
    return;
  int cur_key = cnt(t->l) + add;
  if (cur_key == key)
    merge(t, t->l, t->r);
  else if (cur_key < key)
    erase(t->r, key, add + cnt(t->l) + 1);
  else
    erase(t->l, key, add);
  upd(t);
}

int main() {
  int n, q;
  scanf("%d", &n);
  pitem root = NULL;
  srand(time(NULL));
  for (int i = 0; i < K; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    unsigned int a;
    scanf("%u", &a);
    pitem cur = new item(rand(), a);
    if (root)
      merge(root, root, cur);
    else
      root = cur;
  }
  scanf("%d", &q);
  while (q--) {
    char ty[5];
    unsigned int x, y, k;
    scanf("%s %u", ty, &x);
    if (ty[0] == 'I') {
      scanf("%d", &y);
      pitem t1, t2;
      split(root, t1, t2, x);
      pitem cur = new item(rand(), y);
      merge(root, t1, cur);
      merge(root, root, t2);
    }
    else if (ty[0] == 'D') {
      erase(root, x);
    }
    else if (ty[0] == 'R') {
      scanf("%u", &y);
      replace(root, x, y);
    }
    else if (ty[0] == 'Q') {
      scanf("%u %u", &y, &k);
      pitem t1, t2, t3;
      split(root, t1, t2, x);
      split(t2, t2, t3, y-x+1);
      printf("%u\n", t2->a[k]);
      merge(root, t1, t2);
      merge(root, root, t3);
    }
  }
  return 0;
}