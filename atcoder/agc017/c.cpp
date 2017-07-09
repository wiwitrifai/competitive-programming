#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int a[N], n, m;
int cnt[N];

int dp[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    cnt[a[i]]++;
  }
  for (int t = 0; t < m; t++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    cnt[a[x]]--;
    cnt[y]++;
    a[x] = y;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = 0;
      for (int j = 1; j <= cnt[i] && j <= i; j++)
        dp[i] = max(dp[i], dp[i-j] + j);
      for (int j = cnt[i]+1; j <= i; j++)
        dp[i] = max(dp[i], dp[i-j] + cnt[i]);
    }
    printf("%d\n", n-dp[n]);
  }

  return 0;
}