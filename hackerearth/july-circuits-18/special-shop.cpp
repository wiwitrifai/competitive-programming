#include <bits/stdc++.h>

using namespace std;
int n;
int a, b;
long long calc(int x) {
  long long y = n - x;
  return 1LL * a * x * x + 1LL * b * y * y;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &a, &b);
    int l = 0, r = n;
    while (r - l > 2) {
      int lo = (l + l + r) / 3, ri = (l + r + r) / 3;
      if (calc(lo) < calc(ri))
        r = ri;
      else
        l = lo;
    }
    long long ans = calc(l);
    for (int i = l+1; i <= r; ++i)
      ans = min(ans, calc(i));
    printf("%lld\n", ans);
  }
  return 0;
}