#include <bits/stdc++.h>

using namespace std;

int main() {
  long long m, w, p, n;
  cin >> m >> w >> p >> n;
  if (m > w)
    swap(m, w);
  if ((n+w-1)/w <= m) {
    puts("1");
    return 0;
  }
  long long mw = m * w;
  long long ans = (n + mw-1) / mw;
  long long now = 0, res = 0;
  while (m * w < n && res < n) {
    long long need = n - res;
    mw = m * w;
    ans = min(ans, now + (mw + need-1)/mw);
    if (p <= res) {
      res -= p;
      m++;
      if (m > w)
        swap(m, w);
    }
    else {
      long long k = (p-res + mw - 1)/mw;
      res += mw * k - p;
      now += k;
      m++;
      if (m > w)
        swap(m, w);
    }
  }
  if (n > res) {
    long long need = n - res;
    mw = m * w;
    ans = min(ans, now + (mw-1 + need-1)/mw);
  }
  else
    ans = min(ans, now);
  printf("%lld\n", ans);
  return 0;
}