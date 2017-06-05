#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int dp[N][N], l[8][N], r[N][8], one[N][2]; 
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  map< int, int > mp;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    one[i][0] = one[i][1] = -1;
    if (mp.count(a[i]-1))
      one[i][0] = mp[a[i]-1];
    if (mp.count(a[i]+1))
      one[i][1] = mp[a[i]+1];
    mp[a[i]] = i;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
      if (i > j) {
        dp[i][j] = max(dp[0][j] + 1, dp[i][j]);
        dp[i][j] = max(l[a[i] % 7][j] + 1, dp[i][j]);
        if (one[i][0] != -1)
          dp[i][j] = max(dp[one[i][0]][j] + 1, dp[i][j]);
        if (one[i][1] != -1)
          dp[i][j] = max(dp[one[i][1]][j] + 1, dp[i][j]);
      }
      if (j > i) {
        dp[i][j] = max(dp[i][0] + 1, dp[i][j]);
        dp[i][j] = max(r[i][a[j] % 7] + 1, dp[i][j]);
        if (one[j][0] != -1)
          dp[i][j] = max(dp[i][one[j][0]] + 1, dp[i][j]);
        if (one[j][1] != -1)
          dp[i][j] = max(dp[i][one[j][1]] + 1, dp[i][j]);
      }
      if (i == j) dp[i][j] = 0;
      if (i) {
        l[a[i] % 7][j] = max(l[a[i] % 7][j], dp[i][j]);
      }
      if (j) {
        r[i][a[j] % 7] = max(r[i][a[j] % 7], dp[i][j]);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}