#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int N = 102;
long long dp[N][2*N][1005][3][3];
int n, l, a[N];
int main() {
  scanf("%d%d", &n, &l);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  sort(a, a+n, [](int x, int y) {
    return x > y;
  });
  dp[0][0][0][0] = 1;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<=i*2; j++) {
      for(int k = 0; k<1005; k++) {
        for(int s = 0; s<=2; s++) if(dp[i][j][k][s]) {
          if(k + 2*a[i] < 1005) {
            long long now = (dp[i][j][k][s] * ((mod + 1)/2)) % mod;
            dp[i+1][j+2][k+2*a[i]][s] = (dp[i+1][j+2][k+2*a[i]][s] + now) % mod;
          }
          if(k + a[i] < 1005 && s < 2) {
            dp[i+1][j+1][k+a[i]][s+1] = (dp[i+1][j+1][k+a[i]][s+1] + dp[i][j][k][s]) % mod;
          }
          if(k - 2*a[i] >= 0 && j>=2) {
            long long now = j & 1 ? ((1LL * ((j-1)/2) * j) % mod) : ((1LL * (j/2) * (j-1)) % mod);
            now -= max((j - s)/2, 0);
            now = (now * dp[i][j][k][s]) % mod;
            dp[i+1][j-2][k-2*a[i]][s] = (dp[i+1][j-2][k-2*a[i]][s] + now) % mod;
          }
          if(k - a[i] >= 0 && s < 2)
            dp[i+1][j-1][k-a[i]][s+1] = (dp[i+1][j-1][k-a[i]][s+1] + (dp[i][j][k][s] * j % mod))  % mod;
          dp[i+1][j][k][s] = (dp[i+1][j][k][s] + dp[i][j][k][s]) % mod;
        }
      }
    }
  long long ans = 0;
  for(int i = 0; i<=l; i++)
    ans = (ans + dp[n][0][i][2]) % mod;
  printf("%lld\n", ans);
  return 0;
}