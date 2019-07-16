#include <bits/stdc++.h>

using namespace std;

const int N = 55;

double dp[N][N];
double tmp[N];
long double C[N][N];
vector<int> g[N];
int sz[N];
void dfs(int v, int par = -1) {
  sz[v] = 1;
  dp[v][0] = 1;
  dp[v][1] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    fill(tmp, tmp+sz[u]+1, 0);
    double sum = 0;
    int tot = sz[u] * 2;
    for (int i = 0; i < sz[u]; ++i) {
      tmp[i+1] += dp[u][i] * i / sz[u];
      tmp[0] += dp[u][i] * (sz[u] - i) / tot;
      sum += dp[u][i];
      tmp[i+1] += sum / tot;
    }
    for (int i = 0; i <= sz[u]; ++i)
      dp[u][i] = tmp[i];
    int com = sz[v] + sz[u] - 1;
    for (int i = 0; i <= com; ++i)
      tmp[i] = 0;
    for (int i = 0; i < sz[v]; ++i) {
      for (int j = 0; j <= sz[u]; ++j) {
        int a = i, b = sz[v]-1-i;
        int c = j, d = sz[u] - j;
        double now = dp[v][i] * dp[u][j] / C[com][sz[u]];
        if (c > 0) {
          for (int k = 0; k <= b; ++k) {
            tmp[com-k-d] += now * C[a+b-k+c-1][c-1] * C[k+d][d];
          }
        }
        swap(a, c);
        swap(b, d);
        if (c > 0) {
          for (int k = 0; k <= b; ++k) {
            tmp[com-k-d] += now * C[a+b-k+c-1][c-1] * C[k+d][d];
          }
        }
        if (a == 0 && c == 0) {
          tmp[0] += dp[v][i] * dp[u][j];
        }
      }
    }
    for (int i = 0; i <= com; ++i)
      dp[v][i] = tmp[i];
    sz[v] += sz[u];
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]);
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int s = 0; s < n; ++s) {
    dfs(s);
    printf("%.10lf\n", dp[s][0]);
  }
  return 0;
}