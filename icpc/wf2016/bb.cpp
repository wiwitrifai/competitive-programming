#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6, M = 2e4 + 4;

const long long inf = 2e18 + 5;

inline long long mul(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (inf / a < b) return inf;
  return min(a * b, inf);
}

long long convertBase(long long y, long long from, long long to) {
  long long r = 0, pw = 1;
  while (y) {
    long long d = y % from;
    r += mul(pw, d);
    if (d >= to) return -1;
    if (r > inf) return inf;
    pw = mul(pw, to);
    y /= from;
  }
  return r;
}

int main() {
  long long y, l;
  scanf("%lld %lld", &y, &l);
  long long ans = 10;
  for (long long b = ans + 1; b < N; ++b) {
    long long v = convertBase(y, b, 10);
    if (v >= l)
      ans = max(ans, b);
  }
  for (long long res = l; res < M; ++res) {
    long long le = 11, ri = 1e18;
    while (le < ri) {
      long long mid = (le + ri + 1) >> 1;
      if (convertBase(res, 10, mid) < y)
        ri = mid - 1;
      else
        le = mid;
    }
    if (convertBase(res, 10, le) == y)
      ans = max(ans, le);
  }
  printf("%lld\n", ans);
  return 0;
}
