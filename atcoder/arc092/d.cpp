#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

long long a[N], b[N];

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%lld", b+i);
  for (int lg = 31; lg >= 0; --lg) {
    sort(a, a+n);
    long long dua = 1LL << lg, mask = dua - 1;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      long long now = dua - (mask & b[i]);
      long long satu = lower_bound(a, a+n, now + dua) - lower_bound(a, a+n, now) + lower_bound(a, a+n, now + dua * 3) - lower_bound(a, a+n, now + dua * 2);
      if (b[i] & dua)
        satu = n - satu, b[i] ^= dua;
      cur = (cur + satu) % 2;
    }
    if (cur)
      ans |= (1LL << lg);
    for (int i = 0; i < n; ++i)
      a[i] &= mask;
  }
  printf("%lld\n", ans);
  return 0;
}