#include <bits/stdc++.h>

using namespace std;

const int N = 52, S = 202, K = 2005;

int dp[N][S][K], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s, k;
    scanf("%d %d %d", &n, &s, &k);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= s; j++)
        for (int z = 0; z <= k; z++)
          dp[i][j][z] = -1; 
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      int dec = (n-1-(i-1)) * i;
      for (int j = 0; j <= s; j++) {
        for (int z = 0; z <= k; z++) {
          int jj = j - i, zz = z - dec;
          if (jj >= 0 && zz >= 0 && dp[i][jj][zz] >= 0)
            dp[i][j][z] = i;
          if (dp[i-1][j][z] >= 0)
            dp[i][j][z] = i-1;
        }
      }
    }
    if (dp[n][s][k] < 0)
      puts("-1");
    else {
      int now = n;
      for (int i = 0; i < n; i++)
        ans[i] = 0;
      int sb = s, sk = k;
      while (now > 0) {
        int to = dp[now][s][k];
        assert(to >= 0);
        if (to == now) {
          ans[n-now]++;
          s -= now;
          k -= ((n-1-2*(now-1) + n-1) * now / 2);
        }
        else
          now = to;
      }
      for (int i = 0; i < n; i++)
        ans[i+1] += ans[i];
      for (int i= 0; i < n; i++) {
        sb -= ans[i];
        for (int j = i; j < n; j++)
          sk -= abs(ans[j]-ans[i]);
        if (i)
          assert(ans[i-1] <= ans[i]);
      }
      assert(sb == 0 && sk == 0);
      for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i], (i == n-1) ? '\n' : ' ');
      }
    }
  }
  return 0;
}