#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 88, inf = 1e9 + 7;

int dp[N];
pair<int, int> ant[M];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x, s;
    scanf("%d %d", &x, &s);
    ant[i] = make_pair(x, s);
  }
  fill(dp, dp+m + 2, inf);
  dp[0] = 0;
  sort(ant, ant + n);
  for (int k = 0; k < n; ++k) {
    int x = ant[k].first, s = ant[k].second;
    int cur = inf;
    for (int i = max(0, x - s - 1); i <= min(x + s, m); ++i) {
      cur = min(cur, dp[i]);
      dp[i] = cur;
    }
    for (int r = x + s + 1, l = x - s - 2; l >= 0 || r <= m; --l, ++r) {
      if (l >= 0)
        cur = min(cur, dp[l]);
      dp[min(r, m)] = min(dp[min(r, m)], cur + r - x - s);
    }
  }
  printf("%d\n", dp[m]);
  return 0;
}
