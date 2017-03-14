#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e8;
pair< int, int > dp[N][30], tmp[N][30];
vector< int > child[N];
int n, h, a[N];

void dfs(int v = 0) {
  for (int u : child[v])
    dfs(u);
  for (int i = 0; i <= h; i++) {
    int now = i + a[v], d = 1;
    if (now > h)
      now = a[v], d = 2;
    tmp[0][i] = make_pair(d, now);
  }
  int m = child[v].size();
  int allmask = 1 << m;
  for (int mask = 1; mask < allmask; mask++) {
    for (int off = 0; off <= h; off++) {
      pair< int, int > & cur = tmp[mask][off];
      cur = {inf, inf};
      for(int i = 0; i < m; i++) if (mask & (1<<i)) {
        int bef = mask ^ (1<<i);
        int u = child[v][i];
        int sambung = tmp[bef][off].second;
        pair< int, int > now(tmp[bef][off].first + dp[u][sambung].first-1, dp[u][sambung].second);
        cur = min(cur, now);
      }
    }
  }
  allmask--;
  for (int i = 0; i <= h; i++) {
    dp[v][i] = tmp[allmask][i];
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    for (int i = 0; i < n; i++) {
      int m;
      scanf("%d", &m);
      child[i].clear();
      for (int j = 0; j < m; j++) {
        int u;
        scanf("%d", &u);
        u--;
        child[i].push_back(u);
      }
    }
    dfs();
    printf("%d\n", dp[0][0].first);
  }
  return 0;
}