#include <bits/stdc++.h>

using namespace std;

long long calc(long long l, long long r) {
  if (l > r)
    return 0;
  return (l + r) * (r - l + 1);
}

int find(int n, long long x) {
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    long long cur = calc(mid, n-1);
    if (cur >= x)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long l, r;
    scanf("%d %lld %lld", &n, &l, &r);
    int now = find(n, l);
    for (long long x = l; x <= r; ++x) {
      while (now > 0 && calc(now-1, n-1) < x) --now;
      int sisa = x - calc(now, n-1);
      int level = n - now + 1;
      if (now == 0) {
        printf("1%c", x == r ? '\n' : ' ');
        continue;
      }
      if (sisa & 1)
        printf("%d%c", level, x == r ? '\n' : ' ');
      else
        printf("%d%c", (sisa / 2) + level, x == r ? '\n' : ' ');
    }
  }
  return 0;
}
