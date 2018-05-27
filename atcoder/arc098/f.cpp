#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> g[N];
int a[N], b[N];
int p[N];
bool used[N];
long long sum[N];
priority_queue<pair<int, int> > st[N];

int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }


bool can(long long x) {
  for (int i = 0; i < n; ++i) {
    while (!st[i].empty())
      st[i].pop();
    for (int u : g[i])
      st[i].push(make_pair(-a[u], u));
    sum[i] = b[i];
  }
  fill(p, p+n, -1);
  fill(used, used+n, 0);
  int cnt = 0;
  stack<int> stak;
  for (int i = 0; i < n; ++i) {
    if (x >= a[i]) {
      stak.push(i);
      used[i] = 1;
    }
  }
  // cerr << " cek " << x << endl;
  while (!stak.empty()) {
    int v = stak.top();
    stak.pop();
    v = find(v);
    // cerr << " sumber " << v << endl;
    while (!st[v].empty()) {
      auto it = st[v].top();
      int u = it.second;
      if (a[u] > sum[v] + x) break;
      st[v].pop();
      used[u] = 1;
      u = find(u);
      // cerr << " tambah " << u << endl;
      if (u == v) continue;
      if (st[u].size() > st[v].size()) swap(u, v);
      while (!st[u].empty()) {
        st[v].push(st[u].top());
        st[u].pop();
      }
      sum[v] += sum[u];
      p[u] = v;
    }
  }
  for (int i = 0; i < n; ++i) if (!used[i]) return false;
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", a+i, b+i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v; 
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long lo = 0, hi = 0;
  for (int i = 0; i < n; ++i)
    a[i] -= b[i];
  for (int i = 0; i < n; ++i)
    if (a[i] > hi) hi = a[i];
  long long all = 0;
  for (int i = 0; i < n; ++i)
    all += b[i];
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  // cerr << lo << endl;
  printf("%lld\n", lo+all);
  return 0;
}