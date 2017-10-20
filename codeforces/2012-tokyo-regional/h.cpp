#include <bits/stdc++.h>

using namespace std;

const int N = 111, M = 10010;

bool zero[N];
bool vis[N][N], disjoin[N][N];
int s[M], a[M], b[M];
int n, m;

bool can(int x) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      disjoin[i][j] = 0;
      vis[i][j] = (i == j);
    }
  fill(zero, zero + n + 1, 0);
  for (int i = 0; i < x; i++)
    if (s[i] == 1)
      vis[a[i]][b[i]] = 1;
    else if (s[i] == 2)
      vis[a[i]][b[i]] = vis[b[i]][a[i]] = 1;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        vis[i][j] |= vis[i][k] && vis[k][j];
  for (int i = 0; i < x; i++) {
    if (s[i] == 4) {
      disjoin[a[i]][b[i]] = disjoin[b[i]][a[i]] = 1;
      for (int j = 1; j <= n; j++)
        if (vis[j][a[i]] && vis[j][b[i]])
          zero[j] = 1;
    }
  }
  for (int i = 0; i < x; i++) {
    if (s[i] == 5) {
      if (zero[a[i]] || zero[b[i]]) return false;
      for (int p = 1; p <= n; p++) if (vis[a[i]][p])
        for (int q = 1; q <= n; q++) if (vis[b[i]][q]) {
          if (disjoin[p][q]) return false;
        }
    }
    else if (s[i] == 3) {
      if (zero[a[i]] && zero[b[i]]) return false;
      if (vis[a[i]][b[i]] && vis[b[i]][a[i]]) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  while (n && m) {
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", s+i, a+i, b+i);
    }

    int l = 0, r = m;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (can(mid))
        l = mid;
      else
        r = mid-1;
    }
    printf("%d\n", l);
    scanf("%d %d", &n, &m);
  }  
  return 0;
}