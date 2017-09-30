#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", a+i, b+i);
    if ((k & a[i]) == a[i])
      ans += b[i];
  }
  for (long long mask = 1; mask <= k; mask <<= 1) {
    if ((k & mask) == 0) continue;
    long long now = (mask ^ k) | (mask - 1);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if ((now & a[i]) == a[i])
        cur += b[i];
    }
    ans = max(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}