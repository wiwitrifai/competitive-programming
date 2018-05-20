#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dp[N][N][N];
int get(int last, int r, int b) {
  if (dp[last][r][b] != -1) return dp[last][r][b];
  if (last > r) return 0;
  int & ret = dp[last][r][b];
  ret = get(last+1, r, b);
  for (int j = 0;; ++j) {
    b -= j; r -= last;
    if (!last) --b;
    if (b < 0 || r < 0) break;
    ret = max(ret, 1+j+get(last+1, r, b));
  }
  return ret;
}

void solve(int tc) {
  int r, b;
  scanf("%d %d", &r, &b);
  printf("Case #%d: %d\n", tc, get(0, r, b));
}

int main() {
  int tt;
  scanf("%d", &tt);
  memset(dp, -1, sizeof dp);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
  }
  return 0;
}