#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;

long long calc(long long s, long long cnt, long long beda) {
  if (cnt <= 0)
    return 0;
  long long a = cnt;
  long long b = s + s + beda * (cnt - 1);
  if (a & 1)
    b /= 2;
  else
    a /= 2;
  return (inf / a < b) ? inf : min(a * b, inf);
}

long long findc(long long s, long long x, long long beda) {
  long long lo = 0, hi = 1e10;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    long long val = calc(s, mid, beda);
    if (x < val)
      hi = mid - 1;
    else
      lo = mid;
  }
  return lo;
}

void solve() {
  long long l, r;
  scanf("%lld %lld", &l, &r);
  long long ans = 0;
  long long now = 1;
  if (l > r) {
    long long cnt = findc(now, l-r, 1);
    ans += cnt;
    l -= calc(now, cnt, 1);
    now += cnt;
  }
  else if (r > l) {
    long long cnt = findc(now, r-l, 1);
    ans += cnt;
    r -= calc(now, cnt, 1);
    now += cnt;
  }
  if (l >= r && l >= now) {
    l -= now;
    ++ans;
    ++now;
  }
  if (max(l, r) < now) {
    printf("%lld %lld %lld\n", ans, l, r);
    return;
  }
  long long cntr = findc(now, r, 2);
  long long cntl = findc(now+1, l, 2);
  long long cnt = min(cntl, cntr);
  ans += cnt * 2;
  r -= calc(now, cnt, 2);
  l -= calc(now+1, cnt, 2);
  now += 2 * cnt;
  while (max(l, r) >= now) {
    if (l >= r)
      l -= now;
    else
      r -= now;
    ++ans;
    ++now;
  }
  printf("%lld %lld %lld\n", ans, l, r);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
