#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][N];
long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    for (int j = i+1; j < n; ++j) {
      dp[i][j] = 2;
    }
  }
  if (n == 1) {
    puts("1");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    vector<pair<long long, int>> left, right;
    for (int j = 0; j < i; ++j)
      left.emplace_back(a[j]^a[i], dp[j][i]);
    for (int j = i+1; j < n; ++j)
      right.emplace_back(a[j]^a[i], j);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int j = 0, best = 1;
    for (auto it : right) {
      while (j < left.size() && left[j].first <= it.first) {
        best = max(best, left[j].second);
        ++j;
      }
      dp[i][it.second] = max(dp[i][it.second], best + 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
