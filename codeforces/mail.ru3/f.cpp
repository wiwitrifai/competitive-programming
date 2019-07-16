#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const double inf = 1e18, eps = 1e-7;

double dp[2][N][N * 10];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    double c, t;
    scanf("%lf %lf", &c, &t);
    vector<pair<int, int> > prob(n);
    for (int i = 0; i < n; ++i) {
      int a, p;
      scanf("%d %d", &a, &p);
      prob[i] = {a, p};
    }
    sort(prob.begin(), prob.end());
    reverse(prob.begin(), prob.end());
    int cur = 0, pre = 1, sum = 0;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n * 10; ++k)
          dp[i][j][k] = inf;
      }
    dp[cur][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      swap(cur, pre);
      int a, p;
      a = prob[i].first, p = prob[i].second;
      sum += p;
      for (int j = 0; j <= i+1; ++j) {
        for (int k = 0; k <= sum; ++k) {
          dp[cur][j][k] = dp[pre][j][k];
          if (k >= p && j >= 1) {
            dp[cur][j][k] = min(dp[cur][j][k], (dp[pre][j-1][k-p]+ a) / 0.9);
          }
        }
      }
    }
    int ans = 0;
    for (int score = sum; score >= 0; --score) {
      double best = inf;
      for (int k = 1; k <= n; ++k) {
        if (dp[cur][k][score] >= inf) continue;
        double x = (sqrt(dp[cur][k][score] * c) - 1.0) / c;
        double now = x + 10.0 * k + dp[cur][k][score] / (1.0 + c * x);
        best = min(best, now);
      }
      if (best < t + eps) {
        ans = score;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}