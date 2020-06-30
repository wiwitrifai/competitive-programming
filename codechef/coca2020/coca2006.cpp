#include <bits/stdc++.h>

using namespace std;

const int N = 55, B = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
       r = r * b % mod;
  return r;
}

int dp[N][B];

void add(int & var, int x) {
  var += x;
  if (var >= mod)
    var -= mod;
}

int solve() {
  int n, b;
  scanf("%d %d", &b, &n);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j <= b; ++j) {
      dp[i+1][j] = dp[i][j];
      if (j)
        add(dp[i+1][j], dp[i+1][j-1]);
      if (j > k) {
        add(dp[i+1][j], mod - dp[i][j-k-1]);
      }
    }
  }
  printf("%d\n", dp[n][b]);
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
