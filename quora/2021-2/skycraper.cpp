#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct SegTree {
  int n;
  vector<int> orig;
  vector<int> maxi, lazy;

  SegTree(vector<int> & _orig) : n(_orig.size()), orig(_orig), maxi(2 * n), lazy(2 * n, -1) {
    build(0, 0, n);
  }

  void build(int id, int l, int r) {
    if (r-l < 2) {
      maxi[id] = orig[l];
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    build(il, l, mid);
    build(ir, mid, r);
    maxi[id] = max(maxi[il], maxi[ir]);
  }

  void upd(int id, int v) {
    maxi[id] = v;
    lazy[id] = v;
  }

  void push(int id, int il, int ir) {
    if (lazy[id] == -1) return;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = -1;
  }

  void update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      upd(id, v);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    maxi[id] = max(maxi[il], maxi[ir]);
  }

  int get(int x, int id, int l, int r) {
    if (r-l < 2)
      return maxi[id];
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    return x < mid ? get(x, il, l, mid) : get(x, ir, mid, r);    
  }

  int get(int x) {
    return get(x, 0, 0, n);
  }

  void update(int x, int y, int v) {
    update(x, y, v, 0, 0, n);
  }

  int find_left(int x, int v, int id, int l, int r) {
    if (l > x) return -1;
    if (maxi[id] <= v) {
      return -1;
    }
    if (r-l < 2) {
      return l;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    int res;
    res = find_left(x, v, ir, mid, r);
    if (res == -1)
      res = find_left(x, v, il, l, mid);
    return res;
  }

  int find_left(int x, int v) {
    return find_left(x, v, 0, 0, n);
  }

  int find_right(int x, int v, int id, int l, int r) {
    if (r <= x) return n;
    if (maxi[id] <= v) {
      return n;
    }
    if (r-l < 2) {
      return l;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    int res;
    res = find_right(x, v, il, l, mid);
    if (res == n)
      res = find_right(x, v, ir, mid, r);
    return res;
  }

  int find_right(int x, int v) {
    return find_right(x, v, 0, 0, n);
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  SegTree st(h);
  int t, x, y, z;
  while (q--) {
    scanf("%d %d", &t, &x);
    --x;
    if (t == 1) {
      int val = st.get(x);
      int r = st.find_right(x, val), l = st.find_left(x, val);
      printf("%d\n", r - l - 1);
    } else {
      scanf("%d", &y);
      if (t == 2) {
        st.update(x, x+1, y);
      } else {
        scanf("%d", &z);
        st.update(x, y, z);
      }
    }
  }
  return 0;
}
