#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e8;

char s[N];
int cnt[1<<17][30];
int dp[1<<17];

int main() {
  int n;
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int m = strlen(s);
    int now = 1<<i;
    for (int j = 0; j < m; j++)
      cnt[now][s[j]-'a']++;
    dp[now] = m;
  }
  dp[0] = 0;
  int nn = 1<< n;
  for (int mask = 1; mask < nn; mask++) {
    if (__builtin_popcount(mask) == 1)
      continue;
    int lsb = mask & (-mask);
    int sb = mask ^ lsb;
    int sum = 0;
    for (int j = 0; j < 26; j++) {
      sum += cnt[mask][j] = min(cnt[lsb][j], cnt[sb][j]);
    }
    dp[mask] = inf;
    for (int j = (mask - 1) & mask; j; j = (j - 1) & mask) {
      int k = mask ^ j;
      dp[mask] = min(dp[mask], dp[j] + dp[k]);
    }
    dp[mask] -= sum;
  }
  printf("%d\n", dp[nn-1] + 1);
  return 0;
}