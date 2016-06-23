#include <bits/stdc++.h>

using namespace std;

int n;
double dp[1<<19][19];
double p[20][20];

int main() {
  cin >> n;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
      cin >> p[i][j];

  dp[1][0] = 1;
  int nloop = 1<<n;
  for(int i = 2; i < nloop; i++) {
    for(int j = 0; j<n; j++) if(i & (1<<j)) {
      double sum = 0;
      int mask = i ^ (1<<j);
      for(int k = 0; k < n; k++) if(mask & (1<<k)) {
        sum = max(sum, p[k][j] * dp[mask][k] + p[j][k] * dp[i ^ (1<<k)][j]);
      }
      dp[i][j] = sum;
    }
  }
  double ans = 0;
  for(int i = 0; i<n; i++)
    ans = max(ans, dp[nloop-1][i]);
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}