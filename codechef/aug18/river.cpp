#include <bits/stdc++.h>

using namespace std;

struct segtree {
  vector<int> ma, add;
  int n;
  void reset(int n) {
    this->n = n;
    ma.assign(n << 2, 0);
    add.assign(n << 2, 0);
  }
  void upd(int id, int v) {
    ma[id] += v;
    add[id] += v;
  }
  void push(int id) {
    if (add[id] == 0) return;
    upd(id << 1, add[id]);
    upd((id << 1) | 1, add[id]);
    add[id] = 0;
  }
  void rec_update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      upd(id, v);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    rec_update(x, y, v, il, l, mid);
    rec_update(x, y, v, ir, mid, r);
    ma[id] = max(ma[il], ma[ir]);
  }
  int get_pos(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return -1;
    if (ma[id] <= 0) return -1;
    if (r-l < 2) {
      return l;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    int res = get_pos(x, y, ir, mid, r);
    if (res == -1)
      res = get_pos(x, y, il, l, mid);
    return res;
  }
  int get_neg(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return -1;
    if (ma[id] < 0) return -1;
    if (r-l < 2) {
      return l;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    int res = get_neg(x, y, ir, mid, r);
    if (res == -1)
      res = get_neg(x, y, il, l, mid);
    return res;
  }
  int get_val(int x, int id, int l, int r) {
    if (r-l < 2) {
      return ma[id];
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    return (x < mid) ? get_val(x, il, l, mid) : get_val(x, ir, mid, r);
  }

  void update(int x, int y, int v) {
    rec_update(x, y+1, v, 1, 0, n);
  }
  int query_pos(int x, int y) {
    return get_pos(x, y+1, 1, 0, n);
  }
  int query_neg(int x, int y) {
    return get_neg(x, y+1, 1, 0, n);
  }
  int query_val(int x) {
    return get_val(x, 1, 0, n);
  }
};

const int N = 1e6 + 6;

vector<int> child[N], el[N][2];
int col[N], sz[N], big[N], lv[N], p[N];
int grup[N], nogrup, pos[N], up[N];
segtree seg[N][2];

void get_size(int v) {
  sz[v] = 1;
  big[v] = -1;
  for (int u : child[v]) {
    col[u] = !col[v];
    lv[u] = lv[v] + 1;
    get_size(u);
    sz[v] += sz[u];
    if (big[v] == -1 || sz[u] > sz[big[v]])
      big[v] = u;
  }
}

void hld(int v) {
  grup[v] = nogrup;
  pos[v] = el[nogrup][col[v]].size();
  el[nogrup][col[v]].push_back(v);
  if (big[v] != -1) {
    hld(big[v]);
  }
  for (int u : child[v]) {
    if (u == big[v]) continue;
    ++nogrup;
    up[nogrup] = v;
    hld(u);
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      child[i].clear();
      el[i][0].clear();
      el[i][1].clear();
    }
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
      scanf("%d", p+i);
      --p[i];
      child[p[i]].push_back(i);
    }
    col[0] = lv[0] = 0;
    get_size(0);
    nogrup = 0;
    up[nogrup] = -1;
    hld(0);
    assert(grup[0] == 0);
    ++nogrup;
    for (int i = 0; i < nogrup; ++i) {
      seg[i][0].reset(el[i][0].size());
      seg[i][1].reset(el[i][1].size());
    }
    seg[0][0].update(0, 0, -1);
    int used = 1, unused = 0;

    for (int i = 1; i < n; ++i) {
      int v = i;
      int ci = col[i], co = ci^1;
      while (v >= 0) {
        int last_used = -1, last_unused = -1;
        int u = p[v];
        int ng = grup[v];
        if (u >= 0 && grup[u] != ng)
          u = -1;
        if (col[v] != ci)
          swap(v, u);
        if (v != -1)
          last_used = seg[ng][ci].query_pos(0, pos[v]);
        if (u != -1)
          last_unused = seg[ng][co].query_neg(0, pos[u]);
        if (last_used != -1 || last_unused != -1) {
          int selected = -1;
          if (last_used != -1)
            selected = el[ng][ci][last_used];
          if (last_unused != -1 && (selected == -1 || lv[el[ng][co][last_unused]] > lv[selected]))
            selected = el[ng][co][last_unused];
          if (col[selected] == ci) {
            if (selected != 0)
              ++used, ++unused;
            else
              ++used;
            seg[ng][ci].update(pos[selected], pos[v], -1);
            if (u != -1) {
              int id = last_used;
              while (id < el[ng][co].size() && lv[el[ng][co][id]] < lv[selected]) ++id;
              if (id <= pos[u])
                seg[ng][co].update(id, pos[u], +1);
            }
          }
          else {
            if (selected == 0)
              ++unused;
            seg[ng][co].update(pos[selected], pos[u], +1);
            if (v != -1) {
              int id = last_unused;
              while (id < el[ng][ci].size() && lv[el[ng][ci][id]] < lv[selected]) ++id;
              if (id <= pos[v])
                seg[ng][ci].update(id, pos[v], -1);
            }
          }
          break;
        }
        else {
          if (v != -1) {
            seg[ng][ci].update(0, pos[v], -1);
            if (el[ng][ci][0] == 0)
              ++used;
          }
          if (u != -1) {
            seg[ng][co].update(0, pos[u], +1);
            if (el[ng][co][0] == 0)
              ++unused;
          }
          v = up[ng];
        }
      }
      int ans = min(used, unused);
      if (ans == 1 && i+1 > 3) ++ans;
      ++ans;
      printf("%d%c", ans, i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}