#include <bits/stdc++.h>

using namespace std;

const int N = 111;

double dp[N][N];
double d[N];
vector<pair<int, int> > g[N];
double le[N][N], ri[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    d[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    g[u].emplace_back(u, w);
    d[u] *= (100.0 - w) / 100.0;
  }
  for (int i = 0; i < n; i++) {
    int k = g[i].size();
    fill(le[0], le[0] + k, 0.0);
    fill(ri[k], ri[k] + k, 0.0);
    le[0][0] = ri[k][0] = 1;
    for (int j = 0; j < k; j++) {
      double p = (double)g[i][j].second/100.0;
      for (int z = k; z >= 0; z--) {
        double now = 0;
        now = (1-p) * le[j][z];
        if (z)
          now += p * le[j][z-1];
        le[j+1][z] = now;
      }
    }

    for (int j = k-1; j >= 0; j--) {
      double p = (double)g[i][j].second/100.0;
      for (int z = k; z >= 0; z--) {
        double now = 0;
        now = (1-p) * ri[j+1][z];
        if (z)
          now += p * ri[j+1][z-1];
        ri[j][z] = now;
      }
    }
    for (int j = 0; j < k; j++) {
      double p = (double)g[i][j].second/100.0;
      double now = 0;
      for (int z = 0; z <= k; z++) {
        for (int y = 0; y <= k; y++) {
          now += le[j][z] * ri[j+1][y] * p * 1.0/(z+y+1);
        }
      }
      dp[i][g[i][j].first] += now;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cerr << dp[i][j] << " ";
    cerr << endl;
  }
  cerr << endl;
  double ans = 1;
  for (int i = 0; i < n-1; i++) {
    cerr << i << " " << d[i] << " " << dp[i][i] << endl;
    ans -= d[i]/(1-dp[i][i]);
  }
  printf("%.20lf\n", ans);
  return 0;
}