#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector< int > v[N << 2];
int ans[N], x[N], val[N], n, cs[N];
void build(int id = 1, int l = 0, int r = n) {
  v[id].clear();
  if (r-l < 2) {
    v[id].push_back(val[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  v[id].resize(v[il].size() + v[ir].size());
  merge(v[il].begin(), v[il].end(), v[ir].begin(), v[ir].end(), v[id].begin());
}

int get(int ll, int rr, int low, int id = 1, int l = 0, int r = n) {
  if (ll >= r || rr <= l) return 0;
  if (ll <= l && r <= rr) {
    return distance(lower_bound(v[id].begin(), v[id].end(), low), v[id].end());
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(ll, rr, low, il, l, mid) + get(ll, rr, low, ir, mid, r);
}

int l[N], r[N], cntr = 0;
vector< pair<int, int > > adj[N];

void dfs(int v, int cost = 0, int p = -1) {
  cs[v] = cost;
  x[v] -= cost;
  val[cntr] = x[v];
  l[v] = cntr++;
  for (auto e : adj[v]) if (e.first != p) {
    dfs(e.first, cost + e.second, v);
  }
  r[v] = cntr;
}

int main() {
  freopen("car.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", x+i), adj[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--; b--;
      adj[a].emplace_back(b, c);
      adj[b].emplace_back(a, c);
    }
    cntr = 0;
    dfs(0);
    build();
    for (int i = 0; i < n; i++) {
      if (i)
        printf(" ");
      printf("%d", get(l[i], r[i], -cs[i])-1);
    }
    printf("\n");
  }
  return 0;
}