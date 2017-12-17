// solved by luqman
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 120;
 
long long dp[N][3];
 
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
   
  dp[k][2] = 1;
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i+1][1] += dp[i][0];
    dp[i+k][2] += dp[i][0];
     
    dp[i+1][0] += dp[i][1];
     
    dp[i+1][0] += dp[i][2];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[i][1] + dp[i][2];
  cout << ans << endl;
  return 0;
}