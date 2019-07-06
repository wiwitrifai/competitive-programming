// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N];
pair<long long, int> va[N];

int dp[2][N];

int main() {
  scanf("%d", &n);
  long long maks = 0;
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i), maks = max(maks, a[i]);
  for (int i = 0; i < n; ++i)
    a[i] = maks - a[i];
  int c = 0, b = 1;
  for (int i = 0; i <= n; ++i)
    dp[c][i] = i;
  for (int k = 61; k >= 0; --k) {
    swap(c, b);
    long long mask = (1LL << k) - 1;
    for (int i = 0; i < n; ++i) {
      va[i] = {a[i] & mask, (a[i] >> k)&1};
    }
    sort(va, va+n);
    reverse(va, va+n);
    int one = 0, zero = 0, cone = 0, czero = 0;
    for (int i = 0; i < n; ++i) {
      one += va[i].second;
      czero += va[i].second;
      cone += va[i].second == 0;
    }
    for (int i = 0; i <= n; ++i) {
      if (i) {
        if (va[i-1].second) {
          ++zero;
          ++cone;
          --czero;
        }
        else {
          ++one;
          --cone;
          ++czero;
        }
      }
      dp[c][i] = min(dp[b][zero] + czero, dp[b][one] + cone);
    }
  }
  printf("%d\n", dp[c][0]);
  return 0;
}
