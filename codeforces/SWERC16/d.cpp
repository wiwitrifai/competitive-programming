#include <bits/stdc++.h>

using namespace std;

const int N = 11;

double dp[N][N][N];
bool vis[N][N][N];

int n, cc, d;
bool used[2][55];
double C[55][55];

double solve(int a, int b, int c) {
  if (a > b)
    swap(a, b);
  if ((!a || !b) && !c)
    return 0;
  if (vis[a][b][c])
    return dp[a][b][c];
  vis[a][b][c] = 1;
  double & ret = dp[a][b][c];
  ret = 0;
  for (int i = 0; i <= a; i++) {
    int resa = min(d - i, b);
    for (int j = 0; j <= resa; j++) {
      int resb = min(d - i -j, c);
      for (int k = 0; k <= resb; k++) {
        int res = (i + j + k);
        if (res == 0)
          continue;
        ret += C[a][i] * C[b][j] * C[c][k] * C[n-a-b-c][d-res] * (1 + solve(a-i, b-j, c-k)) / C[n][d];
      }
    }
  }
  double m = (C[n-a-b-c][d]/C[n][d]);
  ret += m;
  ret /= 1 - m;
  return ret;
} 

int main() {
  for (int i = 0; i < 55; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
  scanf("%d %d %d", &n, &d, &cc);
  memset(vis, 0, sizeof vis);
  memset(used, 0, sizeof used);
  for (int k = 0; k < 2; k++)
  for (int i = 0; i < cc; i++) {
    int v;
    scanf("%d", &v);
    used[k][v] = 1;
  }
  int a = 0, b = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    if (used[0][i] && used[1][i])
      c++;
    else if (used[0][i])
      a++;
    else if (used[1][i])
      b++;
  }
  double ans = solve(a, b, c);
  printf("%.9lf\n", ans);
  return 0;
}