#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, inf = 1e6;

int add[N << 2], val[N], mi[N << 2], pos[N << 2];
int n;

inline void upd(int id, int v) {
  if (v == 0) return;
  mi[id] += v;
  add[id] += v;
}

inline void combine(int id, int il, int ir) {
  if (mi[il] <= mi[ir]) {
    pos[id] = pos[il];
    mi[id] = mi[il];
  }
  else {
    pos[id] = pos[ir];
    mi[id] = mi[ir];
  }
}

inline void push(int id, int il, int ir) {
  if (add[id] == 0) return;
  upd(il, add[id]);
  upd(ir, add[id]);
  add[id] = 0;
}

void build(int id = 1, int l = 0, int r = n) {
  add[id] = 0;
  if (r-l < 2) {
    mi[id] = val[l];
    pos[id] = l;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  combine(id, il, ir);
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  combine(id, il, ir);
}

int nxt[N], ans[N];
vector<int> pre[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fill(val, val + n, 0);
    for (int i = 0; i <= n; ++i)
      pre[i].clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", nxt+i);
      --nxt[i];
      if (nxt[i] >= 0) {
        ++val[i+1];
        --val[nxt[i]];
        pre[nxt[i]].push_back(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      val[i+1] += val[i];
      if (nxt[i] >= 0 && nxt[i] < n)
        ++val[i];
    }
    build();
    bool ok = 1;
    for (int i = n; i > 0; --i) {
      if (mi[1] != 0) {
        ok = 0;
        break;
      }
      int v = pos[1];
      ans[v] = i;
      if (nxt[v] >= 0) {
        update(v+1, nxt[v], -1);
      }
      for (int b : pre[v]) {
        update(b, b+1, -1);
      }
      update(v, v+1, inf);
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}
