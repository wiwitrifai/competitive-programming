#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long inf = 1e18;
 
long long dp[N][2];
int a[N];
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < N; i++) {
      dp[i][0] = dp[i][1] = -inf;
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    dp[0][0] = 0;
    long long ans = -inf;
    for(int i = 1; i <= n; i++) {
      dp[i][0] = max((long long)a[i], dp[i - 1][0] + a[i]);
      dp[i][1] = max((long long)a[i], dp[i - 1][1] + a[i]);
      if(i >= 2) {
        dp[i][1] = max(dp[i][1], dp[i - 2][0] + a[i]);
      }
      ans = max(ans, dp[i][0]);
      ans = max(ans, dp[i][1]);
    }
    printf("%lld\n", ans);
  }
  
  return 0;
} 