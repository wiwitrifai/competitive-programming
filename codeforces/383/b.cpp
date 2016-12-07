#include <bits/stdc++.h>

using namespace std;

const int N = 1006;

int n;
int dp[N][N], m, tot, w[N], b[N], p[N];
vector< int > e[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  scanf("%d %d %d", &n, &m, &tot);
  for (int i = 0; i < n; i++)
    scanf("%d", w+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    merge(u, v);
  }
  for (int i = 0; i < n; i++)
    e[find(i)].push_back(i);
  int last = 0;
  for (int i = 0; i < n; i++) if (p[i] < 0) {
    int sumb = 0, sumw = 0;
    for (int v : e[i])
      sumb += b[v], sumw += w[v];
    int best = 0;
    for (int j = 0; j <= tot; j++) {
      best = max(best, dp[last][j]);
      if (j >= sumw)
        best = max(best, dp[last][j-sumw] + sumb);
      for (int v : e[i])
        if (j >= w[v])
          best = max(best, dp[last][j-w[v]] + b[v]);
      dp[last+1][j] = best;
    } 
    last++;
  }
  printf("%d\n", dp[last][tot]);

  return 0;
} 