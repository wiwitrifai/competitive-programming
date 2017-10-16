#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int add[N << 2], nn;
void build(int id = 1, int l = 0, int r = nn) {
  add[id] = 0;
  if (r - l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r); 
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = nn) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    add[id] += v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
}

int get(int x, int id = 1, int l = 0, int r = nn) {
  if (r-l < 2)
    return add[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    return add[id] + get(x, il, l, mid);
  else
    return add[id] + get(x, ir, mid, r);
}
int n, m, k;
vector< pair<int, int> > ad[N], del[N];
vector< pair<int, int> > que[N];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);
    r--; c--;
    int x = r-d, y = c, xx = r, yy = c + d;
    ad[min(max(x + m - y, 0), n+m)].push_back(make_pair(max(0, x+y), min(xx+yy, n + m)));
    x = r, y = c-d, xx = r+d, yy = c;
    del[min(max(x + m - y, 0), n+m) + 1].push_back(make_pair(max(0, x+y), min(xx+yy, n + m)));
    que[min(max(r + m - c, 0), n+m)].push_back(make_pair(i, r + c));
  }
  nn = 2 * (n + m);
  build();
  int ans = -1, ma = -1;
  for (int i = 0; i < m + n; i++) {
    for (auto it : ad[i]) {
      int x = it.first, y = it.second;
      if (x > y) swap(x, y);
      update(x, y+1, +1);
    }
    for (auto it : del[i]) {
      int x = it.first, y = it.second;
      if (x > y) swap(x, y);
      update(x, y+1, -1);
    }
    for (auto it : que[i]) {
      int res = get(it.second);
      if (ma < res || (ma == res && it.first < ans))
        ans = it.first, ma = res;
    }
  }
  printf("%d %d\n", ans+1, ma-1);
  return 0;
}