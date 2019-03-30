#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int s[N], x, n;
int dp[2][N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i);
  sort(s, s+n);
  int c = 0, b = 1;
  for (int i = 0; i < s[0]; ++i) {
    dp[c][i] = i;
  }
  for (int i = 0; i < n; ++i) {
    swap(c, b);
    fill(dp[c], dp[c]+x+1, 0);
    int now = s[i];
    for (int j = 0; j < now && j + now <= x; ++j) {
      dp[c][j+now] = dp[b][j];
    }
    for (int j = 0; j + now <= x; ++j)
      add(dp[c][j+now], dp[c][j]);
    for (int j = 0; j < now; ++j) {
      add(dp[c][j], 1LL * (i + 1) * dp[b][j] % mod);
    }
    for (int j = now; j <= x; ++j) {
      add(dp[c][j], 1LL * i * dp[b][j] % mod);
    }
  }
  printf("%d\n", dp[c][x]);
  return 0;
}
