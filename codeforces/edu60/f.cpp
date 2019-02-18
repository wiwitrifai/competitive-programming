#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, P = 17;

char s[N];
int dp[1 << P], can[P][P];
int c[P][P][1 << P];
int cnt[P];
int last[P];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  scanf("%s", s);
  for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j)
      scanf("%d", can[i]+j);
  fill(dp, dp+(1 << p), 0);
  for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j)
      for (int mask = 0; mask < (1 << p); ++mask)
        c[i][j][mask] = 1;
  memset(last, -1, sizeof last);
  for (int i = 0; i < n; ++i) {
    s[i] -= 'a';
    ++cnt[s[i]];
    for (int j = 0; j < p; ++j) {
      if (can[s[i]][j] || last[j] == -1) continue;
      int mask = (1 << p) - 1;
      for (int k = 0; k < p; ++k) {
        if (last[k] > last[j]) {
          mask ^= 1 << k;
        }
      }
      if ((mask | (1 << s[i]) | (1 << j)) == mask)
        c[s[i]][j][mask] = 0;
    }
    last[s[i]] = i;
  }
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < p; ++j) {
      for (int mask = (1 << p) - 1; mask > 0; --mask) {
        if (c[i][j][mask]) continue;
        for (int k = 0; k < p; ++k) {
          if (k == i || k == j) continue;
          if (mask & (1 << k))
            c[i][j][mask ^ (1 << k)] = 0;
        }
        dp[mask] = N;
      }
    }
  }
  for (int i = 0; i < (1 << p); ++i) {
    if (dp[i] >= N) continue;
    dp[i] = 0;
    for (int j =0; j < p; ++j) {
      if (i & (1 << j))
        dp[i] += cnt[j];
    }
    for (int j = 0; j < p; ++j) {
      if (i & (1 << j)) {
        dp[i] = min(dp[i], dp[i ^ (1 << j)]);
      }
    }
  }
  printf("%d\n", dp[(1 << p)-1]);
  return 0;
}