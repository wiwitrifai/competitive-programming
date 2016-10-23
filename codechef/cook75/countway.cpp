#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 13313;

int dp[N], cnt[N+5];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  k = min(k, n-k);
  sort(cnt, cnt+N);
  int off = 0;
  while (cnt[off] == 0) off++;
  int ma = 0;
  dp[0] = 1;
  for (int i = off; i < N; i++) {
    int p = cnt[i];
    ma += p;
    ma = min(ma, k);
    int sum = 0;
    for (int j = 0; j <= p; j++) {
      if (ma < j)
        break;
      sum += dp[ma-j];
      if (sum >= mod)
        sum -= mod;
    }
    for (int j = ma; j >= 0; j--) {
      int bef = dp[j];
      if (dp[j] != sum)
        dp[j] = sum;
      sum -= bef;
      if (sum < 0)
        sum += mod;
      if (j >= p+1) {
        sum += dp[j-p-1];
        if (sum >= mod)
          sum -= mod;
      }
    }
  }
  printf("%d\n", dp[k]);
  return 0;
}