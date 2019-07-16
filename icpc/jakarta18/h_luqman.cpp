// By Luqman

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, 0);
    push.assign(n << 2, inf);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (l > r) return;
    num[p] = -(r - l + 1);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void relax(int p, int l, int r) {
    if (push[p] != inf) {
      num[p] = (r - l + 1) * push[p];
      if (l < r) {
        push[p + p] = push[p];
        push[p + p + 1] = push[p];
      }
      push[p] = inf;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = num[p + p] + num[p + p + 1];
  }
  void change(int l, int r, int val) {
    if (l <= r) {
      change(1, 0, n - 1, l, r, val);
    }
  }
  void change(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    change(p + p, l, mid, ll, rr, val);
    change(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int sum(int l, int r) {
    if (l <= r) {
      return sum(1, 0, n - 1, l, r);
    }
    return 0;
  }
  int sum(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    int ret = 0;
    ret += sum(p + p, l, mid, ll, rr);
    ret += sum(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }

  vector<int> num, push;
  int n;
};

vector<int> un;
int s[N];
vector<tuple<int, int, int>> lim[N];

int sum(int l, int r) {
  return s[r] - (l? s[l - 1] : 0);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
    if (s[i] == 0) {
      un.push_back(i);
    }
  }
  for (int i = 1; i < n; i++) s[i] += s[i - 1];
  for (int i = 0; i < q; i++) {
    int l, r, wow;
    scanf("%d %d %d", &l, &r, &wow);
    l--; r--;
    lim[r].emplace_back(l, r, wow);
  }
  segtree seg(un.size());
  for (int en = 0; en < n; en++) {
    for (auto it : lim[en]) {
      int a, b, c;
      tie(a, b, c) = it;
      int l = lower_bound(un.begin(), un.end(), a) - un.begin();
      int r = upper_bound(un.begin(), un.end(), b) - un.begin();
      int ori_l = l;
      int ori_r = r;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        int cur = sum(a, b) + seg.sum(ori_l, mid - 1) + (ori_r - mid);
        // printf("%d-%d biasa %d-%d +1 hasilnya %d\n", ori_l, mid-1, mid, ori_r-1, cur);
        // printf("kom %d %d %d\n", sum(a, b), seg.sum(ori_l, mid - 1), (ori_r - mid));
        if (cur < c) {
          r = mid - 1;
        } else {
          l = mid;
        }
      }
      int cur = sum(a, b) + seg.sum(ori_l, l - 1) + (ori_r - l);
      if (cur < c) {
        puts("Impossible");
        return 0;
      }
      // printf("changing %d-%d\n to +1\n", un[l], un[ori_r-1]);
      seg.change(l, ori_r - 1, +1);
      // for (int i = 0; i < un.size(); i++) printf("%d ", seg.sum(i, i)); printf("\n");
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    int now = sum(i, i);
    if (now == 0) {
      int u = lower_bound(un.begin(), un.end(), i) - un.begin();
      printf("%d", seg.sum(u, u));
    } else {
      printf("%d", now);
    }
  }
  printf("\n");
  return 0;
}
