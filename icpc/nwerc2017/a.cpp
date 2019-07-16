#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
vector<int> pos[N];
int tmp[N], dp[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    va[i] = a[i];
  }
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
  }
  n = unique(a, a+n) - a;
  for (int i = 0; i < n; ++i)
    pos[a[i]].push_back(i);
  int ans = n - 1;
  for (int i = 0; i+1 < va.size(); ++i) {
    if (pos[i].size() > 1) {
      fill(tmp, tmp+pos[i].size(), 0);
      int now = 0;
      for (int j = 0; j < pos[i].size(); ++j) {
        tmp[j] = max(tmp[j], now);
        now = max(now, dp[pos[i][j]]);
      }
      now = 0;
      for (int j = (int)pos[i].size()-1; j >= 0; --j) {
        tmp[j] = max(tmp[j], now);
        now = max(now, dp[pos[i][j]]);
      }
      for (int j = 0; j < pos[i].size(); ++j)
        dp[pos[i][j]] = tmp[j];
    }
    int now = 0;
    for (int j : pos[i]) {
      if (a[j+1] == a[j]+1)
        dp[j+1] = max(dp[j+1], dp[j]+1);
      now = max(now, dp[j]);
    }
    for (int j : pos[i+1]) {
      dp[j] = max(dp[j], now);
    }
  }
  int big = 0;
  for (int u : pos[(int)va.size()-1])
    big = max(big, dp[u]);
  ans -= big;
  printf("%d\n", ans);
  return 0;
}