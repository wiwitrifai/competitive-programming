#include <bits/stdc++.h>

using namespace std;

const int N = 55;

double dp[N][N][N];
int cnt[N], p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    for (int i= 0; i < n; i++) {
      int w;
      scanf("%d", &w);
      w--;
      cnt[w]++;
    }
    for (int i= 0; i <= n; i++) {
      scanf("%d", p+i);
    }
    for (int i = 0; i <= n+1; i++)
      for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n; k++)
          dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    int sum = 0, prev = 0;
    for (int i = 0; i <= n; i++) {
      double pp = 1;
      sum += p[i];
      int m = min(sum, n);
      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= j; k++) {
          if (dp[i][j][k] == 0) continue;
          int ma = min(p[i], n-j);
          double q = pp;
          for (int z = 0; z <= ma; z++) {
            int c = min(cnt[i], z);
            dp[i+1][j+z][k+c] += q * dp[i][j][k];
            q *= (double)(p[i]-z)/(sum-j-z) * (j+z+1)/(z+1);
          }
        }
        pp *= (double)(prev - j) / (sum - j);
      }
      prev = sum;
    }
    double ans = 0; 
    for (int i = 0; i <= n; i++) {
      ans += dp[n+1][n][i] * i / (n*2 - i);
    }
    printf("%.12lf\n", ans);
  }

  return 0;
}