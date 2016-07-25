#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e12;

int n, k;
long long dp[N][N];

int main() {
  scanf("%d%d", &n, &k);
  
  for(int i = 0; i<=n; i++) {
    for(int j = 0; j<=k; j++)
      dp[i][j] = -inf;
  }
  dp[0][0] = 0;
  for(int i = 0; i<n; i++) {
    int l, t;
    scanf("%d%d", &l, &t);
    for(int j = 0; j<=k; j++) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]-l);
      dp[i+1][j+t] = max(dp[i+1][j+t], dp[i][j]+l);
    }
  }
  long long ans = -inf;
  for(int i = 0; i<=k; i++)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;

  return 0;
}