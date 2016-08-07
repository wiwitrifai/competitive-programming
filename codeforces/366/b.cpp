#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 6;
const long long inf = 1e18;

long long dp[N][N];
int n, x[N], a[N], b[N], c[N], d[N], s, e;

int main() {
  scanf("%d%d%d", &n, &s, &e);
  for(int i = 1; i<=n; i++) {
    scanf("%d", x+i);
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", a+i);
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", b+i);
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", c+i);
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", d+i);
  }
  for(int i = 0; i<=n; i++)
    dp[0][i] = inf;
  dp[0][0] = 0;
  for(int i = 1; i<=n; i++) {
    dp[i][0] = inf;
    for(int j = i; j<=n; j++)
      dp[i][j] = inf;
    if(i == s) {
      bool tol = s < e;
      for(int j = 0 + (i<n); j<=i; j++) {
        dp[i][j] = inf;
        if(j>0 && s < e)
          dp[i][j] = min(dp[i][j], dp[i-1][j-1] - 2LL * x[i] + (long long)b[i] + (long long)d[i]);
        if(s < e)
          dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)b[i] + (long long)c[i]);
        if(s > e)
          dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)a[i] + (long long)d[i]);
        if(j<i && s > e)
          dp[i][j] = min(dp[i][j], dp[i-1][j+1] + 2LL * x[i] + (long long)a[i] + (long long)c[i]);
      }  
      continue;
    }
    else if(i == e) {
      for(int j = 0 + (i<n); j<=i; j++) {
        dp[i][j] = inf;
        if(j>0 && e < s)
          dp[i][j] = min(dp[i][j], dp[i-1][j-1] - 2LL * x[i] + (long long)b[i] + (long long)d[i]);
        if(e > s)
          dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)b[i] + (long long)c[i]);
        if(e < s)
          dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)a[i] + (long long)d[i]);
        if(j<i && e > s)
          dp[i][j] = min(dp[i][j], dp[i-1][j+1] + 2LL * x[i] + (long long)a[i] + (long long)c[i]);
      }
      continue;
    }
    for(int j = 0 + (i<n); j<=i; j++) {
      dp[i][j] = inf;
      if(j>0)
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] - 2LL * x[i] + (long long)b[i] + (long long)d[i]);
      if(!(j == 1 && e > i && i > s))
        dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)b[i] + (long long)c[i]);
      if(!(j == 1 && e < i && i < s))
        dp[i][j] = min(dp[i][j], dp[i-1][j] + (long long)a[i] + (long long)d[i]);
      if(j<i)
        dp[i][j] = min(dp[i][j], dp[i-1][j+1] + 2LL * x[i] + (long long)a[i] + (long long)c[i]);
    }
  }
  long long ans = dp[n][0];
  if(e < s) {
    ans -= (long long)x[s] - (long long)x[e] + (long long)d[e] + (long long)a[s];
  }
  else {
    ans -= (long long)x[e] - (long long)x[s] + (long long)c[e] + (long long)b[s];
  }
  cout << ans << endl;
  return 0;
}