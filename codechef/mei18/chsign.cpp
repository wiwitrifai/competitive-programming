#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

int a[N];
long long dp[N][2];
pair<int, int> pre[N][2];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a+i);
      if (i == 1)
        dp[i][0] = -a[i], dp[i][1] = a[i], pre[i][0] = pre[i][1] = {0, 0};
      else {
        dp[i][1] = a[i] + dp[i-1][1];
        pre[i][1] = {i-1, 1};
        if (-a[i-1] + a[i] > 0) {
          long long nval = a[i] + dp[i-1][0];
          if (dp[i][1] > nval) {
            pre[i][1] = {i-1, 0};
            dp[i][1] = nval;
          }
        }
        dp[i][0] = inf;
        pre[i][0] = {0, 0};
        if (a[i-1] - a[i] > 0) {
          long long nval = dp[i-2][1] + a[i-1] - a[i];
          if (dp[i][0] > nval) {
            pre[i][0] = {i-2, 1};
            dp[i][0] = nval;
          }
        }
        if (-a[i-2] + a[i-1] - a[i] > 0) {
          long long nval = dp[i-2][0] + a[i-1] - a[i];
          if (dp[i][0] > nval) {
            pre[i][0] = {i-2, 0};
            dp[i][0] = nval;
          }
        }
      }
    }
    int last = 0;
    if (dp[n][0] > dp[n][1])
      last = 1;
    int now = n;
    while (now > 0) {
      if (last == 0)
        a[now] *= -1;
      pair<int, int> nx = pre[now][last];
      now = nx.first;
      last = nx.second;
    }
    for (int i = 1; i <= n; ++i)
      printf("%d%c", a[i], i == n ? '\n' : ' ');
  }
  return 0;
}