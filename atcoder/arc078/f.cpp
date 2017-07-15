#include <bits/stdc++.h>

using namespace std;

const int N = 15, inf = 1e9;

vector< int > g[N];
int can[N][N][1 << 15];
bool vis[N];
int dp[N][N][1 << N];

int n, m, a[N * N], b[N * N], c[N * N];

int solve(int u, int v, int mask) {
  if (!can[u][v][mask]) return -1;
  int & ret = dp[u][v][mask];
  if (ret >= 0) return ret;
  if (u == v) return 0;
  if (__builtin_popcount(mask) <= 2) return 0;
  ret = inf;
  for (int cm = mask; cm; cm = (cm-1) & mask) {
    if ((!(cm & (1<<u))) == (!(cm & (1<<v)))) continue;
    int tot = 0;
    int cur = inf;
    for (int i = 0; i < m; i++) {
      if (!(cm & (1<<a[i]))) continue;
      if (cm & (1<<b[i])) continue;
      int le = a[i], ri = b[i];
      if (cm & (1 << ri)) swap(le, ri);
      tot += c[i];
      int resl = solve(u, le, cm);
      if (resl < 0) continue;
      int resr = solve(ri, v, mask ^ cm);
      if (resr < 0) continue; 
      cur = min(cur, resl + resr -c[i]);
    }
    ret = min(ret, cur + tot);
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", a+i, b+i, c+i);
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  int nmask = 1 << n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        for (int k = 0; k < nmask; k++) {
          can[i][j][k] = 1;
        }
      }
      else {
        for (int k = 0; k < nmask; k++) {
          if (!(k & (1<<i))) continue;
          if (!(k & (1<<j))) continue;
          queue< int > q;
          q.push(i);
          can[i][j][k] = 0;
          memset(vis, 0, sizeof vis);
          vis[i] = 1;
          while (!q.empty()) {
            int v = q.front(); q.pop();
            if (v == j) {
              can[i][j][k] = 1;
              break;
            }
            for (int u : g[v]) if (!vis[u]) {
              if (!(k & (1<<u))) continue;
              vis[u] = 1;
              q.push(u);
            }
          }
        }
      }
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, n-1, nmask-1));
  return 0;
}