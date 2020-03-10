#include <bits/stdc++.h>

using namespace std;

const int inf = 1e5 + 7, N = 505;

int dp[N][N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    dp[i][i] = a[i];
  }
  for (int len = 1; len < n; ++len) {
    for (int i = 0; i + len < n; ++i) {
      int r = i+len;
      dp[i][r] = -1;
      for (int j = i; j < i+len; ++j) {
        if (dp[i][j] == -1 || dp[j+1][r] == -1) continue;
        if (dp[i][j] != dp[j+1][r]) continue;
        dp[i][r] = dp[i][j]+1;
        break;
      }
    }
  }
  vector<int> calc(n+1, inf);
  calc[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (dp[i][j] == -1) continue;
      calc[j+1] = min(calc[j+1], calc[i] + 1);
    }
  }
  printf("%d\n", calc[n]);
  return 0;
}
