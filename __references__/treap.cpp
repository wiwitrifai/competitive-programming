/**
 * Treap = BST + Heap
 * alternative name: - Cartesian Tree
 *                   - Randomized BST
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;
struct item
{
  int prior, key;
  pitem l, r;
  item() {}
  item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};

void split(pitem t, int key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (t->key < key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, r->l), r = t;
}
void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;  
}
void insert(pitem & t, pitem  it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(t->key > it->key ? it->l : it->r, it);
}
void erase(pitem &t, int key) {
  if (!t)
    return;
  else if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
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

int main() {
  
  return 0;
}