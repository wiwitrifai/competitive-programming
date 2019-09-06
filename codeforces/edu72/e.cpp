#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e9 + 7;

int n;

struct RMQ {
  pair<int, int> a[N << 2];
  RMQ() {
    fill(a, a+(N << 2), make_pair(inf, inf));
  }
  pair<int, int> combine(pair<int, int> le, pair<int, int> ri) {
    if (le > ri)
      swap(le, ri);
    le.second = min(le.second, ri.first);
    return le;
  }
  void update(int x, int v, int id = 1, int l = 0, int r = n) {
    if (r-l < 2) {
      a[id] = {v, inf};
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      update(x, v, il, l, mid);
    else
      update(x, v, ir, mid, r);
    a[id] = combine(a[il],a[ir]);
  }
  pair<int, int> get(int x, int y, int id = 1, int l = 0, int r = n) {
    if (x >= r || l >= y) return {inf, inf};
    if (x <= l && r <= y) {
      return a[id];
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return combine(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
};

int a[N];

RMQ rmq[9];

void change(int x, int v) {
  int now = v;
  for (int i = 0; i < 9; ++i) {
    int r = now % 10;
    now /= 10;
    if (r)
      rmq[i].update(x, v);
    else
      rmq[i].update(x, inf);
  }
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    change(i, a[i]);
  }
  while (m--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    --x;
    if (t == 1)
      change(x, y);
    else {
      int ans = -1;
      for (int i = 0; i < 9; ++i) {
        auto res = rmq[i].get(x, y);
        if (res.second >= inf) continue;
        int cur = res.first + res.second;
        if (ans == -1 || cur < ans)
          ans = cur;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
