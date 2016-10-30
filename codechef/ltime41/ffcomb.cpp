#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;
const long long inf = 1e17;
long long dp[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int nn = 1<<n;
    for (int i = 0; i < nn; i++)
      dp[i] = inf;
    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d", &c);
      dp[1<<i] = c;
    }
    for (int i = 0; i < m; i++) {
      int p, c;
      scanf("%d %d", &p, &c);
      int mask = 0;
      while(c--) {
        int b;
        scanf("%d", &b); b--;
        mask |= (1<<b);
      }
      dp[mask] = min(dp[mask], (long long)p);
    }
    for (int i = nn-1; i >= 0; i--) {
      for (int j = 0; j < n; j++) if (i & (1<<j))
        dp[i ^ (1<<j)] = min(dp[i ^ (1<<j)], dp[i]);
    }
    for (int mask = 0; mask < nn; mask++) {
      for (int k = mask; k > 0; k = (k-1) & mask)
        dp[mask] = min(dp[mask], dp[mask ^ k] + dp[k]);
    }
    printf("%lld\n", dp[nn-1]);

  }
  return 0;
}