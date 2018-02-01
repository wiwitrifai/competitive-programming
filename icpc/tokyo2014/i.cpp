#include <bits/stdc++.h>

using namespace std;

const int N = 155;
const long long inf = 1e18;

int r[N], s[N], a, b, n;
long long dp[N][N][2];
bool vis[N][N][2];

long long solve(int pos, int score, int turn) {
  if (pos == n) {
    return score <= 0 ? -inf : inf;
  }
  long long & ret = dp[pos][score][turn];
  if (vis[pos][score][turn])
    return ret;
  vis[pos][score][turn] = 1;
  if (turn == 0) {
    ret = inf;
    ret = min(ret, max(solve(pos+1, score, 0) + r[pos] + 1, 1LL));
    ret = min(ret, solve(pos+1, max(score-s[pos], 0), 1) - r[pos]);
  }
  else {
    ret = -inf;
    ret = max(ret, min(solve(pos+1, max(score-s[pos], 0), 1) - r[pos] - 1, -1LL));
    ret = max(ret, solve(pos+1, score, 0) + r[pos]);
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  int sum = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d %d", r+i, s+i), sum += s[i];
  int ans = 0;
  for (int i = 0; i <= sum; ++i)
    if (solve(0, i, 0) <= a-b)
      ans = i;
  printf("%d %d\n", ans, sum - ans);
  return 0;
}