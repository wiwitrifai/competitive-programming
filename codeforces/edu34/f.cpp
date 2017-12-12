#include <bits/stdc++.h>

using namespace std;

const int R = 4, C = 1024, B = 1 << 12, inf = 1e9 + 7;


char s[R][C];
int dp[C][B];

int main() {
  int c;
  scanf("%d", &c);
  int cost[4];
  for (int i = 0; i < 4; ++i)
    scanf("%d", cost+i);
  for (int i = 0; i < 4; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < 5; j++)
      s[i][c+j] = '.';
  }
  for (int i = 0; i < C; ++i)
    for (int j = 0; j < B; ++j)
      dp[i][j] = inf;
  vector<pair<int, int> > tra;
  for (int d = 1; d <= 4; ++d) {
    for (int f = 0; f + d <= 4; ++f) {
      int mask = 0;
      for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
          mask |= 1 << (j * 4 + i + f);
        }
        tra.emplace_back((B-1) ^ mask, cost[d-1]);
      }
    }
  }
  int awal = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; j++) {
      if (s[i][j] == '.') continue;
      awal |= 1 << (j * 4 + i);
    }
  }
  dp[0][awal] = 0;
  for (int i = 0; i <= c; ++i) {
    for (int mask = B-1; mask >= 0; --mask) {
      if (dp[i][mask] >= inf) continue;
      dp[i+1][0] = min(dp[i+1][0], dp[i][mask] + cost[3]);
      for (auto it : tra) {
        int nmask = mask & it.first;
        if (nmask == mask) continue;
        dp[i][nmask] = min(dp[i][nmask], dp[i][mask] + it.second);
      }
      if (mask & 15) continue;
      int nmask = mask >> 4;
      for (int j = 0; j < 4; j++) {
        if (s[j][i+3] == '.') continue;
        nmask |= 1 << (8 + j);
      }
      dp[i+1][nmask] = min(dp[i+1][nmask], dp[i][mask]);
    }
  }
  printf("%d\n", dp[c][0]);
  return 0;
}