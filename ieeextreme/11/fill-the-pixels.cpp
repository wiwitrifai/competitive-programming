#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];
int dxp[] = {1, -1, 0, 0};
int dyp[] = {0, 0, 1, -1};
int dxx[] = {-1, 1, -1, 1};
int dyx[] = {1, 1, -1, -1};
int dxb[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dyb[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool vis[N][N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs_plus(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int ti = i + dxp[k];
    int tj = j + dyp[k];
    if (!valid(ti, tj)) continue;
    if (s[ti][tj] != '1') continue;
    dfs_plus(ti, tj);
  }
}

void dfs_kali(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int ti = i + dxx[k];
    int tj = j + dyx[k];
    if (!valid(ti, tj)) continue;
    if (s[ti][tj] != '1') continue;
    dfs_kali(ti, tj);
  }
}

void dfs_bom(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  for (int k = 0; k < 8; k++) {
    int ti = i + dxb[k];
    int tj = j + dyb[k];
    if (!valid(ti, tj)) continue;
    if (s[ti][tj] != '1') continue;
    dfs_bom(ti, tj);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    swap(n, m);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int a = 0, b = 0, c = 0;
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !vis[i][j]) {
          dfs_plus(i, j);
          a++;
        }
      }
    }
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !vis[i][j]) {
          dfs_kali(i, j);
          b++;
        }
      }
    }
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !vis[i][j]) {
          dfs_bom(i, j);
          c++;
        }
      }
    }
    printf("%d %d %d\n", a, b, c);
  }

  return 0;
}
