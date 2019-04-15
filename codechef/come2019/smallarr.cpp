#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, x;
long long sum[N];

int main() {
  scanf("%d %d", &n, &x);
  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sum[i+1] = sum[i] + a;
  }
  double ans = sum[n];
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      long long now = sum[j] - sum[i];
      long long tot = sum[n] - now;
      double cur = tot + (double)now / x;
      ans = min(ans, cur);
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
