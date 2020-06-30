#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 303;

bool can[N][N][N];
long long dp[N][N][N];


void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int one = 0;
  for (int i = 0; i < n; ++i)
    one += s[i] == '1';
  int zero = n - one;
  queue<tuple<int, int, int>> que;

  auto check = [&](int x, int y, int z) {
    if (can[x][y][z]) {
      return;
    }
    can[x][y][z] = true;
    que.emplace(x, y, z);
  };

  check(0, 0, 0);
  while (!que.empty()) {
    int i, j, k;
    tie(i, j, k) = que.front();
    que.pop();
    if (i+1 <= n) {
      if (j) {
        check(i+1, j - 1 + (s[i] == '0'), k + (s[i] == '1'));
      }
      if (k) {
        check(i+1, j + (s[i] == '0'), k - 1 + (s[i] == '1'));
      }
    }
    if (j+k > 1) {
      if (j)
        check(i, j-1, k);
      if (k)
        check(i, j, k-1);
    }
    if (i + 2 <= n) {
      check(i+2, j + (s[i] == '0'), k + (s[i] == '1'));
      check(i+2, j + (s[i+1] == '0'), k + (s[i+1] == '1'));
    }
    if (i > 0) {
      if (j && s[i-1] == '0')
        check(i-1, j-1, k);
      if (k && s[i-1] == '1')
        check(i-1, j, k-1);
    }
  }
  dp[n][0][0] = 1;
  long long ans = 1;
  for (int i = n; i >= 1; --i) {
    char c = s[i-1];
    for (int j = 0; j <= zero; ++j) {
      for (int k = 0; k <= one; ++k) {
        if (dp[i][j][k] == 0) continue;
        if (c == '1') {
          add(dp[i][j+1][k], dp[i][j][k]);
        } else {
          add(dp[i][j][k+1], dp[i][j][k]);
        }
        add(dp[i-1][j][k], dp[i][j][k]);
        if (can[i][j][k]) {
          add(ans, dp[i][j][k]);
        }
      }
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
