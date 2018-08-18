#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i)
    scanf("%d", a+i);
  sort(a, a+2*n);
  long long ans = 1LL * (a[2 * n-1] - a[0]) * (a[n-1] - a[0]);
  ans = min(ans, 1LL * (a[2 * n-1] - a[n]) * (a[n-1] - a[0]));
  for (int i = 0; i <= n; ++i) {
    ans = min(ans, 1LL * (a[2 * n-1] - a[0]) * (a[i+n-1] - a[i]));
  }
  printf("%lld\n", ans);
  return 0;
}