#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int g[N][N];
int col[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(g, 0, sizeof g);
  for (int i = 0; i < n; i++)
    g[i][i] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    g[a][b] = 1;
    g[b][a] = 1; 
  }
  for (int i = 0; i < n; i++)
    col[i] = g[0][i];
  bool ok = 1;
  for (int i = 0; i < n && ok; i++) {
    for (int j = 0; j < n && ok; j++) {
      if (g[i][j]) {
        if (col[i] != col[j]) {
          ok = 0;
          break;
        }
      }
      else {
        if (col[i] == col[j]) {
          ok = 0;
          break;
        }
      }
    }
  }
  puts(ok ? "DA" : "NE");
  return 0;
}