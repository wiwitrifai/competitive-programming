#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef struct item * pitem;
struct item
{
  pair<int, int> key;
  int prior;
  int val, maxval;
  pitem l, r;
  item() {}
  item(pair<int, int> key_, int prior_, int val_) : key(key_), prior(prior_), val(val_), l(NULL), r(NULL) {}
};
int max_val(pitem t) {
  return t ? t->maxval : -1;
}
void upd_maxval(pitem it) {
  if (it) {
    it->maxval = max(max(max_val(it->l), max_val(it->r)), it->val);
  }
}
void split(pitem t, pair<int, int> key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (t->key < key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, t->l), r = t;
  upd_maxval(l);
  upd_maxval(r);
}
void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r; 
  upd_maxval(t); 
}
void insert(pitem & t, pitem  it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(t->key > it->key ? t->l : t->r, it);
  upd_maxval(t);
}
void erase(pitem &t, pair<int, int> key) {
  if (!t)
    return;
  else if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
  upd_maxval(t);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int;

struct SegTree {
  int n;
  vector<pitem> node;
  SegTree(int n_) : n(n_), node(n_ << 2, NULL) {}

  void _add(pair<int, int> key, int val, int pos, int id, int l, int r) {
    insert(node[id], new item(key, rnd_int(rng), val));
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (pos < mid)
      _add(key, val, pos, il, l, mid);
    else
      _add(key, val, pos, ir, mid, r);
  }

  void add(pair<int, int> key, int val, int pos) {
    _add(key, val, pos, 1, 0, n);
  }

  void _remove(pair<int, int> key, int pos, int id, int l, int r) {
    erase(node[id], key);
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (pos < mid)
      _remove(key, pos, il, l, mid);
    else
      _remove(key, pos, ir, mid, r);
  }

  void remove(pair<int, int> key, int pos) {
    _remove(key, pos, 1, 0, n);
  }

  int _get(int ylow, int yhig, int xrig, int id, int l, int r) {
    if (r-1 <= xrig) {
      int ret = -1;
      pitem tmp1, tmp2;
      split(node[id], make_pair(ylow, -1), tmp1, node[id]);
      split(node[id], make_pair(yhig, -1), node[id], tmp2);
      if (max_val(node[id]) >= xrig) {
        ret = node[id]->key.second;
      }
      merge(node[id], node[id], tmp2);
      merge(node[id], tmp1, node[id]);
      return ret;
    }
    if (l > xrig)
      return -1;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    int res = _get(ylow, yhig, xrig, il, l, mid);
    if (res == -1)
      res = _get(ylow, yhig, xrig, ir, mid, r);
    return res;
  }
  int get(int ylow, int yhig, int xrig) {
    return _get(ylow, yhig+1, xrig, 1, 0, n);
  }
};

int x[N], y[N], com[N];
vector<int> px[N], py[N];
vector<pair<int, int>> hor[N], ver[N];

bool isver[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vx(n), vy(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, y+i);
    vx[i] = x[i];
    vy[i] = y[i];
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  for (int i = 0; i < n; ++i) {
    x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
    y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
    px[x[i]].push_back(i);
    py[y[i]].push_back(i);
  }
  vector<bool> vis(n, false);
  int ncomp = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    queue<int> que;
    que.push(i);
    int cnt = 0;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      if (vis[v]) continue;
      ++cnt;
      com[v] = ncomp;
      vis[v] = 1;
      if (px[x[v]].size() == 2) {
        int u = px[x[v]][0] ^ px[x[v]][1] ^ v;
        if (!vis[u]) {
          ver[ncomp].emplace_back(v, u);
          que.push(u);
        }
      }
      if (py[y[v]].size() == 2) {
        int u = py[y[v]][0] ^ py[y[v]][1] ^ v;
        if (!vis[u]) {
          hor[ncomp].emplace_back(v, u);
          que.push(u);
        }
      }
    }
    if (cnt & 1) {
      puts("NE");
      return 0;
    }
    ++ncomp;
  }
  vector<pair<int, int>> ans;
  SegTree tree(vx.size());
  queue<int> que;
  for (int i = 0; i < ncomp; ++i) {
    if (hor[i].size() < ver[i].size()) {
      isver[i] = true;
      que.push(i);
    }
    else {
      for (auto it : hor[i]) {
        int u = it.first, v = it.second;
        if (x[u] > x[v])
          swap(u, v);
        tree.add(make_pair(y[u], u), x[v], x[u]);
      }
    }
  }
  while (!que.empty()) {
    int c = que.front(); que.pop();
    for (auto it : ver[c]) {
      int u = it.first, v = it.second;
      if (y[u] > y[v])
        swap(u, v);
      while (1) {
        int res = tree.get(y[u], y[v], x[u]);
        if (res == -1 || isver[com[res]]) break;
        res = com[res];
        isver[res] = true;
        que.push(res);
        for (auto e : hor[res]) {
          int a = e.first, b = e.second;
          if (x[a] > x[b])
            swap(a, b);
          tree.remove(make_pair(y[a], a), x[a]); 
        }
      }
    }
  }
  for (int i = 0; i < ncomp; ++i) {
    if (hor[i].size() > ver[i].size() && isver[i]) {
      puts("NE");
      return 0;
    }
  }
  puts("DA");
  for (int i = 0; i < ncomp; ++i) {
    if (isver[i]) {
      for (auto & e : ver[i]) {
        if (e.first > e.second)
          swap(e.first, e.second);
        printf("%d %d\n", e.first+1, e.second+1);
      }
    }
    else {
      for (auto & e : hor[i]) {
        if (e.first > e.second)
          swap(e.first, e.second);
        printf("%d %d\n", e.first+1, e.second+1);
      }
    }
  }
  return 0;
}
