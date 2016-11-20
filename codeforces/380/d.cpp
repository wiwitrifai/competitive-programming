#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

int dp[2201][201][101][2];
bool vis[2201][201][101][2];
int n, a[4040], sum[4040];

int solve(int l, int diff, int k, int player) {
  if (vis[l][abs(diff)][k][player])
    return dp[l][abs(diff)][k][player];
  vis[l][abs(diff)][k][player] = 1;
  int & ret = dp[l][abs(diff)][k][player];
  int r = l + diff;
  if (l + r + k > n)
    return 0;
  if (player) {
    int v1 = -solve(l, diff+k, k, 0) + sum[n-r] - sum[n-r-k];
    int v2 = -inf;
    if (l + r + k + 1 <= n)
      v2 = -solve(l, diff+k+1, k+1, 0) + sum[n-r] - sum[n-r-k-1];
    ret = max(v1, v2);
  }
  else {
    int v1 = -solve(l+k, diff-k, k, 1) + sum[l+k] - sum[l];
    int v2 = -inf;
    if (l + r + k + 1 <= n)
      v2 = -solve(l+k+1, diff-k-1, k+1, 1) + sum[l+k+1] - sum[l];
    ret = max(v1, v2);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  sum[0] = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), sum[i+1] = sum[i] + a[i];
  printf("%d\n", solve(0, 0, 1, 0));
  return 0;
}