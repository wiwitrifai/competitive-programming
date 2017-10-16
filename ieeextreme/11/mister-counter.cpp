#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N], p[N];

struct segtree { 
  segtree(int n) : n(n) {
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if (l == r) {
      num[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
  }
  int find(int l, int r, int v) {
    return find(1, 0, n - 1, l, r, v);
  }
  int find(int p, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) return upper_bound(num[p].begin(), num[p].end(), v) - num[p].begin();
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr, v) + find(p + p + 1, mid + 1, r, ll, rr, v);
  }
  vector<int> num[N << 2];
  int n;
};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  segtree seg(n);
  p[0] = -1;
  for (int i = 0; i + 1 < n; i++) {
    if (i) p[i] = p[i - 1];
    if (a[i] < a[i + 1]) {
      p[i] = i;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u == v) {
      puts("0");
    } else {
      if (p[v - 1] < u) {
        puts("0");
      } else {
        //printf("lala %d %d\n", v, p[v - 1]);
        int ans = v - p[v - 1] + 1;
        if (ans % 2 == 0) {
          if (seg.find(v - ans + 1, v, a[v - ans + 1]) != ans / 2) {
            ans--;
          }
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
