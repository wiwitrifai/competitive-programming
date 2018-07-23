#include <bits/stdc++.h>

using namespace std;


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

const int N = 1e5 + 5;

int a[N], mul[N];

pitem t[N];
vector<int> divs[N];

void change(int x, int y) {
  for (int d : divs[a[x]])
    erase(t[d], x);
  for (int d : divs[y])
    insert(t[d], new item(x, rand() * rand()));
  a[x] = y;
}
int calc(int l, int r, int d) {
  pitem t1 = t[d], t2, t3;
  split(t1, l, t1, t2);
  split(t2, r, t2, t3);
  int ans = cnt(t2);
  merge(t2, t2, t3);
  merge(t1, t1, t2);
  return ans;
}
long long get(int l, int r, int g) {
  long long ret = r-l;
  for (int d : divs[g]) {
    if (mul[d] == 0) continue;
    ret += mul[d] * calc(l, r, d);
  }
  return ret;
}

bool iscomp[N];

int main() {
  fill(mul, mul+N, 1);
  for (int i = 2; i < N; ++i) if (mul[i]) {
    int x = iscomp[i] ? 1 : -1;
    for (int j = i; j < N; j += i)
      divs[j].push_back(i), mul[j] *= x, iscomp[j] = 1;
    long long ii = 1LL * i * i;
    for (long long j = ii; j < N; j += ii)
      mul[j] = 0;
  }
  srand(time(0));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    for (int d : divs[a[i]])
      insert(t[d], new item(i, rand() * rand()));
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int ty, x, y, z;
    scanf("%d %d %d", &ty, &x, &y);
    if (ty == 1) {
      change(x-1, y);
    }
    else {
      int z;
      scanf("%d", &z);
      printf("%lld\n", get(x-1, y, z));
    }
  }
  return 0;
}