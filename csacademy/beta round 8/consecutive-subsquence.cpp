#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N][2];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    dp[x][0] = max(dp[x][0], dp[x-1][0] + 1);
    if(x > 1)
      dp[x][1] = max(dp[x][1], dp[x-2][0] + 2);
    dp[x][1] = max(dp[x][1], dp[x-1][1] + 1);
  }
  int ans = 0;
  for(int i = 1; i<N; i++) {
    ans = max(ans, max(dp[i][0] + 1, dp[i][1]));
  }
  printf("%d\n", ans);

  return 0;
}
