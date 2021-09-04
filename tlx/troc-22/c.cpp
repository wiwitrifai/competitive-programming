#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 10;

long long dp[N][K];

long long cost[K][K];
bool exist[K], used[K];
char s[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%lld", cost[i]+j);
    }
  }
  for (int i = 0; i < n; ++i) {
    s[i] -= '1';
  }
  long long all = 0;
  exist[s[0]] = 1;
  for (int i = 1; i < n; ++i) {
    all += cost[s[i-1]][s[i]];
    long long cur = 0;
    bool ada = false;
    for (int j = 0; j < k; ++j) {
      dp[i][j] = dp[i-1][j];
    }
    for (int j = 0; j < k; ++j) {
      if (!exist[j]) continue;
      if (ada) {
        cur = min(cur, dp[i-1][j] + cost[j][s[i]]);
      } else {
        cur = dp[i-1][j] + cost[j][s[i]];
        ada = 1;
      }
    }
    if (used[s[i]])
      cur = min(dp[i][s[i]], cur);
    dp[i][s[i]] = cur;
    used[s[i]] = 1;
    exist[s[i]] = 1;
  }
  printf("%lld\n", all - dp[n-1][s[n-1]]);
  return 0;
}
