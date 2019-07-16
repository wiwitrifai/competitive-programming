#include <bits/stdc++.h>

using namespace std;

const int N = 2048;
const long long inf = 1e17; 

long long dp[2][N * 100];

int main() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int, int> > ev;
  for (int i = 0; i < n; ++i) {
    int c, f, v;
    scanf("%d %d %d", &c, &f, &v);
    ev.emplace_back(-f, -1, c, v);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int c, f, v;
    scanf("%d %d %d", &c, &f, &v);
    ev.emplace_back(-f, +1, c, v);
  }
  sort(ev.begin(), ev.end());
  int sum = 0;
  int cur = 0, bef = 1;
  for (int i = 0; i < N * 100; ++i)
    dp[0][i] = -inf;
  for (int i = 0; i < N * 100; ++i)
    dp[1][i] = -inf;
  dp[cur][0] = 0;
  long long ans = 0;
  for (auto it : ev) {
    swap(cur, bef);
    int c, f, v, x;
    tie(f, x, c, v) = it;
    if (x < 0)
      sum += c;
    c *= x;
    v *= x;
    for (int i = 0; i <= sum; ++i) {
      dp[cur][i] = dp[bef][i];
      if (0 <= i + c && i + c <= sum)
        dp[cur][i] = max(dp[cur][i], dp[bef][i+c] + v);
      ans = max(dp[cur][i], ans);
    }
  }
  printf("%lld\n", ans);
  return 0;
}