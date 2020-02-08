#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct SegTree {
  int n;
  vector<set<pair<int, int>>> node;
  SegTree(int n_) : n(n_), node(n_ << 2) {}

  void _add(pair<int, int> key, int lef, int rig, int id, int l, int r) {
    if (l >= rig || lef >= r) return;
    if (lef <= l && r <= rig) {
      node[id].insert(key);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    _add(key, lef, rig, il, l, mid);
    _add(key, lef, rig, ir, mid, r);
  }

  void add(pair<int, int> key, int lef, int rig) {
    _add(key, lef, rig, 1, 0, n);
  }

  void _remove(pair<int, int> key, int lef, int rig, int id, int l, int r) {
    if (l >= rig || lef >= r) return;
    if (lef <= l && r <= rig) {
      node[id].erase(key);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    _remove(key, lef, rig, il, l, mid);
    _remove(key, lef, rig, ir, mid, r);
  }

  void remove(pair<int, int> key, int lef, int rig) {
    _remove(key, lef, rig, 1, 0, n);
  }

  int _get(int ylow, int yhig, int x, int id, int l, int r) {
    auto it = node[id].lower_bound(make_pair(ylow, -1));
    if (it != node[id].end() && it->first < yhig)
      return it->second;
    if (r-l < 2) {
      return -1;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return x < mid ? _get(ylow, yhig, x, il, l, mid) :
                     _get(ylow, yhig, x, ir, mid, r);
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
        tree.add(make_pair(y[u], u), x[u], x[v]+1);
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
        int res = tree.get(y[u], y[v]+1, x[u]);
        if (res == -1 || isver[com[res]]) break;
        res = com[res];
        isver[res] = true;
        que.push(res);
        for (auto e : hor[res]) {
          int a = e.first, b = e.second;
          if (x[a] > x[b])
            swap(a, b);
          tree.remove(make_pair(y[a], a), x[a], x[b]+1);
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
