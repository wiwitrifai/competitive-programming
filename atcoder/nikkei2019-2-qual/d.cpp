#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const long long infll = 1e18;
vector<pair<int, int>> g[N];
int num[N], n;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    num[l] = id;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  g[il].emplace_back(id, 0);
  g[ir].emplace_back(id, 0);
  build(il, l, mid);
  build(ir, mid, r);
}

void add(int x, int y, pair<int, int> v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    g[id].push_back(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, v, il, l, mid);
  add(x, y, v, ir, mid, r);
}

long long dist[N];

int main() {
  int m;
  scanf("%d %d", &n, &m);
  build();
  for (int i = 0; i < m; ++i) {
    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);
    --l, --r;
    add(l, r, make_pair(num[r], c));
  }
  priority_queue<pair<long long, int> > pq;
  pq.emplace(0, num[0]);
  fill(dist, dist+N, infll);
  dist[num[0]] = 0;
  while (!pq.empty()) {
    long long d = -pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (dist[v] != d) continue;
    for (auto e : g[v]) {
      long long newd = d + e.second;
      if (newd < dist[e.first]) {
        dist[e.first] = newd;
        pq.emplace(-newd, e.first);
      }
    }
  }
  long long ans = dist[num[n-1]];
  if (ans >= infll)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}
