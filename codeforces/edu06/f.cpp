#include <bits/stdc++.h>

using namespace std;

int func(int x) {
  int r = x % 4;
  if (r == 0)
    return x;
  if (r == 1)
    return 1;
  if (r == 2)
    return x + 1; 
  return 0;
}

struct node {
  node * l, * r;
  node(node * l = NULL, node * r = NULL) : l(l), r(r) {
  }
  node * add(int v) {

    node * now = this;
    node * cur = new node(now->l, now->r);
    node * ret = cur;
    int i;
    for (i = 1<<20; i; i>>=1) {
      if (v & i) {
        if (now->r == NULL)
          break;
        now = now->r;
        cur->r = new node(now->l, now->r);
        cur = cur->r;
      }
      else {
        if (now->l == NULL)
          break;
        now = now->l;
        cur->l = new node(now->l, now->r);
        cur->l = now->l;
      }
    }
    for (; i; i>>=1) {
      if (v & i) {
        cur->r = new node();
        cur = cur->r;
      }
      else {
        cur->l = new node();
        cur = cur->l;
      }
    }
    return ret;
  }
  int get(int v) {
    node * now = this;
    int ret = 0;
    for (int i = 1<<20; i; i>>=1) {
      if (v & i) {
        if (now->l) {
          ret |= i;
          now = now->l;
        }
        else if (now->r)
          now = now->r;
        else
          return 0;
      }
      else {
        if (now->r) {
          ret |= i;
          now = now->r;
        }
        else if (now->l)
          now = now->l;
        else
          return 0;      
      }
    }
    return ret;
  }
};

const int N = 5e4 + 5;
vector < node * > trie[N<<2];
vector < int > val[N<<2];
int a[N];
int n;

void build(int id = 1, int l = 0, int r = n) {
  trie[id].push_back( new node());
  val[id].push_back(-1);
  if (r-l < 2) {
    return;
  }
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

int get(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 0;
  if (x <= l && r <= y) {
    int it = lower_bound(val[id].begin(), val[id].end(), make_pair(v, NULL)) - val[id].begin();
    if (it == 0)
      return 0;
    it--;
    return trie[id][it]->get(v);
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  return max(get(x, y, v, il, l, mid), get(x, y, v, ir, mid, r));
}

void upd(int x, int v, int id = 1, int l = 0, int r = n) {
  if (a[x] > val[id].back()) {
    val[id].push_back(a[x]);
    trie[id].push_back(trie[id].back().second->add(v));
  }
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  if (x < mid)
    upd(x, v, il, l, mid);
  else
    upd(x, v, ir, mid, r);
}

pair <int, int> aa[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), aa[i] = {a[i], i};
  build();
  sort(aa, aa+n);
  for (int i = 0; i < n; i++)
    upd(aa[i].second, func(aa[i].first-1));
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r;
    l--;
    int ans = 0;
    for (int i = l; i < r; i++)
      ans = max(ans, get(l, r, func(a[i])));
    printf("%d\n", ans);
  }
  return 0;
}