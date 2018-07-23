#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int> > g[N];
long long rmq[N << 2], sum[N], cur[N];
int n;
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    rmq[id] = sum[l] + cur[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  rmq[id] = min(rmq[il], rmq[ir]);
}

void update(int x, long long v, int id = 1, int l = 0, int r = n) {
  if (r - l < 2) {
    cur[l] = v;
    rmq[id] = sum[l] + v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  rmq[id] = min(rmq[il], rmq[ir]);
}

long long d[N];

void dijkstra(int v) {
  fill(d, d+n, inf);
  priority_queue<pair<long long, int> > pq;
  d[v] = 0;
  pq.push(make_pair(0, v));
  while (!pq.empty()) {
    auto it = pq.top(); pq.pop();
    int v = it.second;
    if (-it.first != d[v]) continue;
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        pq.push(make_pair(-d[u], u));
      }
    }
  }
}

int main() {
  int m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    int u, v;
    int w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    cur[i] = 1LL * (n-1) * (a + b + c);
  }
  dijkstra(0);
  for (int i = 0; i < n; ++i)
    sum[i] = d[i];
  dijkstra(n-1);
  for (int i = 0; i < n; ++i)
    sum[i] += d[i];
  build();
  while (q--) {
    int v, a, b, c;
    scanf("%d %d %d %d", &v, &a, &b, &c);
    --v;
    update(v, 1LL * (n-1) * (a + b + c));
    printf("%lld\n", rmq[1]);
  }
  return 0;
}