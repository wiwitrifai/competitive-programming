#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct seg_tree {
  int cum[N];
  long long cnt[N<<2];
  int st[N<<2], lazy[N<<2];
  int n;
  seg_tree(int n, int *a, int *ccum) {
    for (int i = 0; i < N; i++) 
      cum[i] = ccum[i];
    build(1, 0, n, a);
  }
  void build(int id, int l, int r, int * a) {
    lazy[id] = 0;
    st[id] = 0;
    if (r-l < 2) {
      cnt[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid, a);
    build(ir, mid, r, a);
    cnt[id] = cnt[il] + cnt[ir];
  }
  void upd(int id, int l, int r, int ss, int v) {
    if (ss > 0) {
      int add = cum[r-l+ss-1] - cum[ss-1];
      cnt[id] = add;
      lazy[id] = 0;
      st[id] = ss;
    }
    cnt[id] += 1LL * (r-l) * v;
    lazy[id] += v;
  }
  void shift(int id, int l, int r) {
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    upd(il, l, mid, st[id], lazy[id]);
    upd(ir, mid, r, (st[id] ? (st[id] + mid - l) : 0), lazy[id]);
    st[id] = 0;
    lazy[id] = 0;
  }
  void update(int x, int y, int ss, int v, int id, int l, int r) {
    if (x >= r || y <= l) return;
    if (x <= l && r <= y) {
      upd(id, l, r, ss ? l-x+ss : 0, v);
      return;
    }
    shift(id, l, r);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    update(x, y, ss, v, il, l, mid);
    update(x, y, ss, v, ir, mid, r);
    cnt[id] = cnt[il] + cnt[ir];
  }
  long long get(int x, int y, int id, int l, int r) {
    if (x >= r || y <= l) return 0LL;
    if (x <= l && r <= y) {
      return cnt[id];
    }
    shift(id, l, r);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  }
};
int n, m, a[N], a2[N], a5[N];
int cum2[N], cum5[N];

int main() {
  cum2[0] = 0;
  cum5[0] = 0;
  for (int i = 1; i < N; i++) {
    cum2[i] = cum2[i-1];
    int now = i;
    while ((now % 2) == 0) {
      cum2[i]++;
      now /= 2;
    }
    now = i;
    cum5[i] = cum5[i-1];
    while ((now % 5) == 0) {
      cum5[i]++;
      now /= 5;
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      a2[i] = 0;
      int now = a[i];
      while ((now % 2) == 0) {
        a2[i]++;
        now /= 2;
      } 
      a5[i] = 0;
      while ((now % 5) == 0) {
        a5[i]++;
        now /= 5;
      }
    }
    long long ans = 0;
    seg_tree * s2, * s5;
    s2 = new seg_tree(n, a2, cum2);
    s5 = new seg_tree(n, a5, cum5);
    while (m--) {
      int ty, l, r, x;
      scanf("%d %d %d", &ty, &l, &r);
      l--;
      if (ty == 1) {
        scanf("%d", &x);
        int y = 0;
        while ((x % 2) == 0) {
          y++;
          x /= 2;
        }
        s2->update(l, r, 0, y, 1, 0, n);
        y = 0;
        while ((x % 5) == 0) {
          y++;
          x /= 5;
        }
        s5->update(l, r, 0, y, 1, 0, n);
      }
      else if (ty == 2) {
        scanf("%d", &x);
        int y = 0;
        while ((x % 2) == 0) {
          y++;
          x /= 2;
        }
        s2->update(l, r, 1, y, 1, 0, n);
        y = 0;
        while ((x % 5) == 0) {
          y++;
          x /= 5;
        }
        s5->update(l, r, 1, y, 1, 0, n); 
      }
      else {
        long long now = min(s2->get(l, r, 1, 0, n), s5->get(l, r, 1, 0, n));
        // printf("%lld %lld\n", now);
        ans += now;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}