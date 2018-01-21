
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int dp[2][2], pre[2][2];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    int ans = n+1;
    if (n & 1) {
      memset(dp, 0, sizeof dp);
      for (int i = n/2-1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j)
          for (int k = 0; k < 2; ++k)
            pre[j][k] = dp[j][k], dp[j][k] = n+1;
        for (int j = 0; j < 2; ++j) {
          int le = a[i+1], ri = a[n-1-i-1];
          if (j)
            swap(le, ri);
          for (int k = 0; k < 2; ++k) {
            int nowl = a[i], nowr = a[n-1-i];
            if (k) swap(nowl, nowr);
            // up
            if (nowl > le && nowr > ri)
              dp[k][0] = min(dp[k][0], pre[j][1] + k);
            if (nowl < le && nowr < ri)
              dp[k][1] = min(dp[k][1], pre[j][0] + k);
          }
        }
      }
      for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
          ans = min(ans, dp[i][j]);
    }
    else {
      for (int i = 0; i < 2; ++i) {
        int le = a[n/2-1], ri = a[n-1-n/2+1];
        if (i) swap(le, ri);
        dp[i][0] = n+1;
        dp[i][1] = n+1;
        if (le < ri)
          dp[i][0] = i;
        if (le > ri)
          dp[i][1] = i;
      }
      for (int i = n/2-2; i >= 0; --i) {
        for (int j = 0; j < 2; ++j)
          for (int k = 0; k < 2; ++k)
            pre[j][k] = dp[j][k], dp[j][k] = n+1;
        for (int j = 0; j < 2; ++j) {
          int le = a[i+1], ri = a[n-1-i-1];
          if (j)
            swap(le, ri);
          for (int k = 0; k < 2; ++k) {
            int nowl = a[i], nowr = a[n-1-i];
            if (k) swap(nowl, nowr);
            if (nowl < le && nowr > ri)
              dp[k][0] = min(dp[k][0], pre[j][1] + k);
            if (nowl > le && nowr < ri)
              dp[k][1] = min(dp[k][1], pre  [j][0] + k);
          }
        }
      }
      for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
          ans = min(ans, dp[i][j]);
    }
    if (ans >= n) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}