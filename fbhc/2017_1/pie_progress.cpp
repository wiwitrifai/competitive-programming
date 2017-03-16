#include <bits/stdc++.h>

using namespace std;

const int N = 303;
const long long inf = 1e14;

long long dp[N][N];
long long c[N][N];

int main() {
  time_t start_t = clock();
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%lld", c[i]+j);
      }
      sort(c[i], c[i]+m);
      long long sum = 0;
      for (int j = 0; j < m; j++) {
        long long tmp = c[i][j];
        c[i][j] = sum + 1LL * j * j;
        sum += tmp;
      }
      c[i][m] = sum + 1LL * m * m;
    }
    dp[0][0] = 0;
    for (int j = 1; j <= n; j++)
      dp[0][j] = inf;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) dp[i][j] = inf;
      for (int j = i; j <= n; j++) {
        dp[i][j] = inf;
        int mi = min(m, j);
        for (int k = 0; k <= mi; k++) {
          long long tmp = dp[i-1][j-k] + c[i-1][k];
          if (dp[i][j] > tmp)
            dp[i][j] = tmp;
        }
      }
    }
    printf("Case #%d: %lld\n", tc, dp[n][n]);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}