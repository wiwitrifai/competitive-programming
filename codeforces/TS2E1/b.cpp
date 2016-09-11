#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
const long long inf = 1e17;

long long dp[N];
int x[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", x+i);
      long long sum = x[i];
      dp[i] = inf;
      int ma = min(i, m);
      for (int j = 1; j <= ma; j++) {
        if (sum >= m) {
          dp[i] = min(dp[i], dp[i-j] + 1LL * (sum - m) * a);
        }
        else
          dp[i] = min(dp[i], dp[i-j] + 1LL * (m - sum) * b);
        sum += x[i-j];
      }
      assert(dp[i] < inf);
    }
    printf("%I64d\n", dp[n]);
  }
  return 0;
}