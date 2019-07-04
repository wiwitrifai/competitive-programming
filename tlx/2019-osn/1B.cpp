#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

int n;
long long mins[N << 2];
vector<pair<int, int>> trans[N];

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mins[id] = inf;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

void update(int x, long long v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mins[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) {
    return mins[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  int m, s;
  scanf("%d %d %d", &n, &m, &s);
  ++n;
  for (int i = 0; i < m; ++i) {
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    --a;
    trans[b].emplace_back(a, p);
  }
  build();
  update(0, 0);
  for (int i = 1; i < n; ++i) {
    long long best = get(i-1, i) + s;
    for (auto it : trans[i]) {
      best = min(best, get(it.first, i) + it.second);
    }
    update(i, best);
  }
  printf("%lld\n", get(n-1, n));
  return 0;
}
