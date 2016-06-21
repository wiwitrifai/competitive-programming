#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector< vector< vector< long long > > > dp;
int n, l, a[15];
int main() {
  scanf("%d%d", &n, &l);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  vector< long long > x(l+2, 0);
  vector< vector<long long> > y(n+1, x);
  dp.assign(1<<n, y);
  int len = 1<< n;
  for(int i = 0; i<n; i++)
    dp[1<<i][i][0] = 1;
  for(int mask = 1; mask < len; mask++) {
    for(int j = 0; j<n; j++) if(mask & (1<<j)) {
      for(int k = 0; k<=l; k++) if(dp[mask][j][k]) {
        for(int i = 0; i<n; i++) { 
          int nmask = mask | (1<<i), nl = k + abs(a[j] - a[i]);
          if(nmask != mask && nl <= l)
            dp[nmask][i][nl] = (dp[nmask][i][nl] + dp[mask][j][k]) % mod;
        }
      }
    }
  }  
  long long ans = 0;
  len--;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<=l; j++)
      ans = (ans + dp[len][i][j]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}