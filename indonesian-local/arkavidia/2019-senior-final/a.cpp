#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

bool dp[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int x = n;
    fill(dp, dp+n+1, 0);
    dp[0] = 1;
    for (int i = 2; i <= x; ++i) {
      if (x % i) continue;
      for (int j = 0; j+i <= n; ++j) {
        dp[j+i] |= dp[j];
      }
      while ((x % i) == 0) x /= i;
    }
    puts(dp[m] && dp[n-m] ? "YA" : "TIDAK");
  }
  return 0;
}