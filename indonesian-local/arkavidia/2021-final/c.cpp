#include <bits/stdc++.h>

using namespace std;

const int N = 707, inf = 1e9 + 7;

int cost[26];
int dp[N][N];

int last[N][N];
char s[N];
int k;

int solve(int l, int r) {
  if (r-l == 1) {
    return cost[s[l]-'a'];
  }
  int & ret = dp[l][r];
  if (ret != -1)
    return ret;
  ret = inf;
  for (int i = l+1; i < r; ++i) {
    ret = min(ret, solve(l, i) + solve(i, r));
  }
  int len = r-l;
  for (int x  = 1; x < len; ++x) {
    if (len % x) continue;
    if (last[l][x] < r) continue;
    ret = min(ret, k + solve(l, l+x));
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &k);
  for (int i = 0; i < 26; ++i)
    scanf("%d", cost+i);
  for (int i = 0; i < n; ++i) {
    for (int len = 1; len <= n-i; ++len) {
      int now = i + len;
      while (now < n && s[now] == s[now - len]) ++now;
      last[i][len] = now;
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = solve(0, n);
  printf("%d\n", ans);
  return 0;
}
