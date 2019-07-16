#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
int dp[N][N];
int n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char c[] = "UDLR";

int rec(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return 1;
  if (dp[x][y] != -1)
    return dp[x][y];
  dp[x][y] = 0;
  for (int i = 0; i < 4; ++i)
    if (s[x][y] == c[i]) {
      dp[x][y] = rec(x+dx[i], y+dy[i]);
    }
  return dp[x][y];
}


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      ans += rec(i, j);
  printf("%d\n", ans);
  return 0;
}