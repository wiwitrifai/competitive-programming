#include <bits/stdc++.h>

using namespace std;

const int N = 21;

long long dp[N][1<<N];

class Clicountingd2 {
public:
  int count(vector <string> g) {
    int n = g.size();
    int tot = 1<<n;
    dp[0][0] = 0;
    for(int i = 1; i<tot; i++) {
      dp[0][i] = -1;
    }
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<tot; j++) {
        dp[i+1][j] = -1;
      }
      for(int j = 0; j<tot; j++) {
        if(dp[i][j] == -1)
          continue;
        bool ok = true
        int cnt = 0, all = 0;
        for(int k = 0; k < n; k++) {
          all += g[i][k] == '?';
          if((j & (1<<k))) {
            if(g[i][k] == '?')
              cnt++;
            else if(g[i][k] == '0')
              ok = false;
            break;
          }
        }
        if(ok) {
          int mask = j | (1<<k);
          if(dp[i][mask] == -1)
            dp[i][mask] = 0;
          all -= cnt;
          int on = __builtin_popcount(mask);
          dp[i][mask] += (1LL<<all) * on;
          dp[i][j] += (1LL<<all) * ((1LL<<cnt)-1) * (on-1);
        }
        else {
          int on = __builtin_popcount(j);
          dp[i][j] += (1LL<<all) * on;
        }
      }
    }
    long long ans = 0;
    for(int i = 0; i<tot; i++)
      ans += dp[n][i];
  }
}