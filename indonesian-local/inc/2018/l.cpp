#include <bits/stdc++.h>

using namespace std;

const int N = 16, M = 1 << N;

int bisa[N][M];
int cost[N][N], n;
int can(int s, int mask) {
  if (__builtin_popcount(mask) <= 1)
    return 1;
  int & ret = bisa[s][mask];
  if (ret != -1)
    return ret;
  assert((mask & (1 << s)) > 0);
  int need = __builtin_popcount(mask) / 2;
  ret = 0;
  for (int m = (mask - 1) & mask; m > 0; m = (m-1) & mask) {
    if (__builtin_popcount(m) != need) continue;
    int a = m, b = mask ^ m;
    assert((a | b) == mask);
    if (b & (1 << s))
      swap(a, b);
    for (int j = 0; j < n; ++j) {
      if (cost[s][j] <= 0) continue;
      if ((b & (1 <<j )) == 0) continue;
      if (can(s, a) && can(j, b)) {
        return ret = 1;
      }
    }
  }
  return ret;
}

const int inf = 1e9 + 7;
int dp[M];

int calc(int mask) {
  if (mask == 1)
    return 0;
  int & ret = dp[mask];
  if (ret != -1)
    return ret;
  ret = inf;
  int need = __builtin_popcount(mask) / 2;
  for (int m = (mask - 1) & mask; m > 0; m = (m-1) & mask) {
    if (__builtin_popcount(m) != need) continue;
    int a = m, b = mask ^ m;
    if (b & 1)
      swap(a, b);
    for (int j = 0; j < n; ++j) {
      if (cost[0][j] <= 0) continue;
      if ((b & (1 << j)) == 0) continue;
      if (!can(0, a) || !can(j, b)) continue;
      ret = min(ret, calc(a) + cost[0][j]);
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  memset(bisa, -1, sizeof bisa);
  memset(dp, -1, sizeof dp);
  n = 1 << n;
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j)
      scanf("%d", cost[i]+j);
  int ans = calc((1 << n)-1);
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}