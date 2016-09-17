#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e16;

long long sparse[N][18];
vector< int > adj[N];
vector< pair<int, int > > tickets[N];
long long d[N];
int n, m;
long long get(int l, int r) {
  int k = r - l + 1;
  int lk = 31 - __builtin_clz(k);
  return min(sparse[l + (1<<lk) - 1][lk], sparse[r][lk]);
}
void dfs(int v, int lv = 0) {
  if (v) {
    d[v] = inf;
    for (auto it : tickets[v]) {
      d[v] = min(get(max(0, lv - it.first), lv-1) + it.second, d[v]);
    }
  }
  else
    d[v] = 0;
  sparse[lv][0] = d[v];
  for (int i = 0; i < 17; i++)
    sparse[lv][i+1] = min(sparse[lv][i], lv >= (1<<i) ? sparse[lv - (1<<i)][i] : inf);
  for (int u : adj[v]) {
    dfs(u, lv+1);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    adj[b].push_back(a);
  }
  for (int i = 0; i < m; i++) {
    int v, k, w;
    scanf("%d %d %d", &v, &k, &w);
    v--;
    tickets[v].push_back(make_pair(k, w));
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  while (q--) {
    int h;
    scanf("%d", &h);
    printf("%lld\n", d[h-1]);
  }
  return 0;
}