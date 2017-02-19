#include <bits/stdc++.h>


using namespace std;

const int N = 1280, mod = 1e9 + 7;
long long dp[N][N], tmp[N][N];

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 0; i <= n; i++)
    tmp[0][i] = 1;
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = tmp[i-j][j];
      cerr << dp[i][j] << " ";
      if (i-j < 1 || a[i-j+1] < a[i-j])
        break; 
    }
    cerr << endl;
    for (int j = i; j >= 1; j--) if (dp[i][j]) {
      long long cur = dp[i][j];
      for (int k = 1; k <= j; k++) {
        cur = (cur * (j-k+1)) % mod;
        tmp[i][k] += cur;
        if (tmp[i][k] >= mod) tmp[i][k] -= mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + dp[n][i]) % mod;
  printf("%lld\n", ans);
  return 0;
}