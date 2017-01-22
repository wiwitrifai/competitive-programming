#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t[N];
long long dp[N];
int cost[2], d[2];

int main() {
  int n;
  scanf("%d", &n);
  t[0] = dp[0] = 0;
  int l[2];
  l[0] = l[1] = 1;
  cost[0] = 50; cost[1] = 120;
  d[0] = 90; d[1] = 1440;
  for (int i = 1; i <= n; i++) {
    scanf("%d", t+i);
    dp[i] = dp[i-1] + 20;
    for (int j = 0; j < 2; j++) {
      while (t[l[j]] + d[j] - 1 < t[i]) {
        l[j]++;
      }
      dp[i] = min(dp[i], dp[l[j]-1] + cost[j]);
    }
    printf("%I64d\n", max(0LL, dp[i] - dp[i-1]));
  }
  return 0;
}