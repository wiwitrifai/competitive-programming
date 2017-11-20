#include <bits/stdc++.h>

using namespace std;

const int N = 555;

int dp[N][N];

vector<pair<int, int> > ans; 
int n, m;

int get(int r, int c) {
  if (dp[r][c] != -1) return dp[r][c];
  if (n <= r || m <= c) {
    dp[r][c] = 0;
    return 0;
  }
  dp[r][c] = 0;
  if (r+2 <= n) {
    dp[r][c] = max(dp[r][c], get(r+2, c) + m - c - (c == 0));
  }
  if (c+2 <= m) {
    dp[r][c] = max(dp[r][c], get(r, c+2) + n - r - (r == 0));
  }
  if (r+1 <= n && r > 0) {
    dp[r][c] = max(dp[r][c], get(r+1, c) + (m - c) / 2);
  }
  if (c+1 <= m && c > 0) {
    dp[r][c] = max(dp[r][c], get(r, c+1) + (n - r) / 2);
  }
  return dp[r][c];
}
void solve(int r, int c) {
  if (n <= r) return;
  if (m <= c) return;

  if (r + 2 <= n && dp[r][c] == get(r+2, c) + m - c - (c == 0)) {
    for (int i = max(c-1, 0); i + 1 < m; i++)
      ans.emplace_back(r, i);
    solve(r+2, c);
  }
  else if (c + 2 <= m && dp[r][c] == get(r, c+2) + n - r - (r == 0)) {
    for (int i = max(r-1, 0); i + 1 < n; i++)
      ans.emplace_back(i, c);
    solve(r, c + 2);
  }
  else if (r + 1 <= n && r > 0 && dp[r][c] == get(r+1, c) + (m - c) / 2) {
    for (int i = c; i + 1 < m; i+= 2)
      ans.emplace_back(r-1, i);
    solve(r+1, c);
  }
  else if (c+1 <= m && c > 0 && dp[r][c] == get(r, c+1) + (n - r) / 2) {
    for (int i = r; i + 1 < n; i += 2)
      ans.emplace_back(i, c-1);
    solve(r, c+1);
  }
}


int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &m);
  get(0, 0);
  solve(0, 0);
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first + 1, it.second + 1);
  return 0;
}