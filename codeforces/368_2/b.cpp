#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

vector< pair< int, int > > adj[N];
bool stg[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int u, v, l;
    scanf("%d %d %d", &u, &v, &l);
    adj[u].emplace_back(v, l);
    adj[v].emplace_back(u, l);
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    stg[x] = 1;
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) if (stg[i]) {
    for (auto u : adj[i]) if (!stg[u.first]) {
      ans = min(ans, u.second);
    }
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);

  return 0;
}