#include <bits/stdc++.h>

using namespace std;

__int128 issqr(__int128 x) {
  __int128 s = sqrt((long double)x);
  __int128 lo = s/2, hi = s * 2;
  while (lo < hi) {
    __int128 mid = (lo + hi) >> 1;
    __int128 res = mid * mid;
    if (res == x)
      return mid;
    if (res < x)
      lo = mid+1;
    else
      hi = mid-1;
  }
  if (lo * lo == x)
    return lo;
  return -1;
}

const long long inf = 1e18;

int main() {
  long long x;
  scanf("%lld", &x);
  long long ans = 0;
  vector<long long> fib(2, 1);
  while (fib.back() < inf) {
    long long res = fib.back() + fib[(int)fib.size()-2];
    fib.push_back(res);
  }
  for (long long i : fib) {
    if (i > x) continue;
    __int128 val = (__int128)5 * i * i;
    __int128 n = issqr(val+4), m = issqr(val-4);
    if (n != -1)
      ans = max(ans, (long long)((i + n) / 2));
    if (m != -1)
      ans = max(ans, (long long)((i + m) / 2));
  }
  printf("%lld\n", ans);
  return 0;
}
