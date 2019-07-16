#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, x, a[N];
long long sum[N];

int main() {
  scanf("%d %d", &n, &x);
  sum[0] = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), sum[i+1] = sum[i] + a[i];
  long long ans = -1;
  for (int c = 1; c <= n; ++c) {
    long long now = 1LL * c * x;
    int last = 0;
    for (int i = n, cur = 1; i > 0; i -= c, ++cur) {
      int from = max(i-c, 0);
      long long w = 1LL * (cur+1) * (cur+1);
      long long z = sum[i] - sum[from];
      z -= sum[max(i - c, 0)] - sum[max(from - c, 0)];
      now += w * z;
    }
    now += sum[n] - sum[n-c];
    if (ans < 0 || ans > now)
      ans = now;
  }
  ans += 1LL * x * n;
  printf("%lld\n", ans);
  return 0;
}