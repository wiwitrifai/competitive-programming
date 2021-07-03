#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

struct SegTree {
  int n;
  vector<int> a, mini;
  SegTree(vector<int> _a) : n(_a.size()), a(_a), mini(a.size() * 2) {
    build(0, 0, n);
  }
  void build(int id, int l, int r) {
    if (r-l < 2) {
      mini[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid - l) * 2;
    build(il, l, mid);
    build(ir, mid, r);
    mini[id] = min(mini[il], mini[ir]);
  }
  int get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return inf;
    if (x <= l && r <= y) return mini[id];
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid - l) * 2;
    return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
  int get(int x, int y) {
    return get(x, y, 0, 0, n);
  }

  void update(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      a[x] = v;
      mini[id] = v;
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid - l) * 2;
    if (x < mid)
      update(x, v, il, l, mid);
    else
      update(x, v, ir, mid, r);
    mini[id] = min(mini[il], mini[ir]);
  }
  void update(int x, int v) {
    update(x, v, 0, 0, n);
  }
};

void die() {
  puts("Gasabi");
  exit(0);
}

void ok() {
  puts("Sabi");
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }
  SegTree st(a);
  vector<int> nxt(n, n), lst(n, n);
  for (int i = n-1; i >= 0; --i) {
    int pre = lst[a[i]];
    nxt[i] = pre;
    lst[a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    int pos = lst[b[i]];
    if (pos >= n) {
      die();
    }
    int mini = st.get(0, pos);
    if (mini < b[i]) {
      die();
    }
    st.update(pos, inf);
    lst[b[i]] = nxt[pos];
  }
  ok();
  return 0;
}
