#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], l[N], r[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l+i, r+i);
    a[i*2] = l[i];
    a[i*2+1] = r[i];
  }
  int m = 2 * n;
  sort(a, a+m);
  m = unique(a, a+m) - a;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += l[i] - a[0];
    l[i] = lower_bound(a, a+m, l[i]) - a;
    r[i] = lower_bound(a, a+m, r[i]) - a;
    b[l[i]]--;
    b[r[i]]--;
  }
  long long now = ans;
  int cur = n;
  for (int i = 0; i < m; i++) {
    ans = min(ans, now);
    if (i)
      now -= 1LL * (a[i] - a[i-1]) * cur;
    cur += b[i];
  }
  printf("%lld\n", ans);
  return 0;
}