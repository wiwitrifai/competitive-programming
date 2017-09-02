#include <bits/stdc++.h>

using namespace std;

const int N = 202, inf = 1e9 + 7;

int dp[N][N];
int a[N], b[N];
vector<pair<int, int> > seg;

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
  }
  vector<int> good;
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (a[i] == a[j] && b[i] == b[j]) {
        if (i > j)
          ok = 1;
      }
      else if (a[i] <= a[j] && b[j] <= b[i])
        ok = 1;
    }
    if (ok)
      good.push_back(b[i] - a[i]);
    else
      seg.emplace_back(a[i], b[i]);
  }
  sort(seg.begin(), seg.end());
  n = seg.size();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= p; j++)
      dp[i][j] = -1;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= p; j++) {
      int le = -inf, ri = inf;
      for (int k = i-1; k >= 0; k--) {
        le = max(le, seg[k].first);
        ri = min(ri, seg[k].second);
        if (le >= ri) break;
        if (dp[k][j-1] == -1) continue;
        dp[i][j] = max(dp[i][j], dp[k][j-1] + ri - le);
      }
    }
  }
  sort(good.begin(), good.end());
  reverse(good.begin(), good.end());
  int ans = 0, sum = 0;
  for (int i = 0; i < p; i++) {
    if (dp[n][p-i] != -1)
      ans = max(ans, dp[n][p-i] + sum);
    if (i == good.size()) break;
    sum += good[i];
  }
  printf("%d\n", ans);
  return 0;
}