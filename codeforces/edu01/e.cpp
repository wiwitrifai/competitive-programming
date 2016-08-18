#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

int dp[32][32][52];

int main() {
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 1; k <= 50; k++)
      dp[i][j][k] = inf;      
    }
  }
  dp[1][1][0] = 0;
  dp[1][1][1] = 0;
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      int mk = min(50, i *j);
      for (int k = 1; k <= mk; k++) {
        dp[i][j][k] = inf;
        for (int a = 1; a < i; a++) {
          int mb = min(a * j, k);
          for (int b = max(0, k-(i-a)*j); b <= mb; b++) {
            dp[i][j][k] = min(dp[i][j][k], j*j + dp[a][j][b]+dp[i-a][j][k-b]);
          }
        }
        for (int a = 1; a < j; a++) {
          int mb = min(a * i, k);
          for (int b = max(0, k-(j-a)*i); b <= mb; b++) {
            dp[i][j][k] = min(dp[i][j][k], i*i + dp[i][a][b]+dp[i][j-a][k-b]);
          }
        }
      }
      dp[i][j][0] = 0;
      if (i * j <= 50)
        dp[i][j][mk] = 0; 
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", dp[n][m][k]);
  }
  return 0;
}