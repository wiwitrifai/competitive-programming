/**
 *  ACM ICPC Regional Jakarta 2016 - G : All Are Equal
 */


#include <bits/stdc++.h>

using namespace std;

const int N = 202;

long double dp[N][N][N], sum[N][N];

int n, l[N], r[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", l+i, r+i);
      v.push_back(l[i]-1);
      v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
      l[i] = lower_bound(v.begin(), v.end(), l[i]-1) - v.begin();
      r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < v.size(); j++)
        dp[0][i][j] = 0;
    for (int i = 0; i < n; i++)
      sum[0][i] = 0;
    for (int i = l[0]; i < r[0]; i++) {
      dp[0][0][i] = (long double)(v[i+1] - v[i]) / (v[r[0]] - v[l[0]]);
    }
    sum[0][0] = 1;
    for (int i = 1; i < n; i++) {
      int range = v[r[i]] - v[l[i]];
      for (int j = 0; j < n; j++) {
        sum[i][j] = 0;
        for (int k = 0; k < v.size(); k++) {
          dp[i][j][k] = 0;
          if (k < l[i] || k >= r[i]) continue;
          dp[i][j][k] = dp[i-1][j][k] / range;
          if (j > 0) {
            dp[i][j][k] += (sum[i-1][j-1] - dp[i-1][j-1][k]) * (v[k+1] - v[k]) / range + dp[i-1][j-1][k] * (v[k+1] - v[k] - 1) / range;
          }
          sum[i][j] += dp[i][j][k];
        }
      }
    }
    long double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += sum[n-1][i] * pow(i, 1.5);
    }
    printf("Case #%d: %.20lf\n", tc, (double)ans);
  }
  return 0;
}