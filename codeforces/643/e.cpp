#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long a, r, m;
  scanf("%d %lld %lld %lld", &n, &a, &r, &m);
  m = min(m, a + r);
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  sort(h.begin(), h.end());
  vector<long long> sum(n+1, 0);
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + h[i];
  }
  long long ans = min((sum[n] - 1LL * h[0] * n) * r, (1LL * h[n-1] * n - sum[n]) * a);
  for (int l = 0; l + 1 < n; ++l) {
    long long suml = sum[l+1], sumr = sum[n] - sum[l+1];
    long long cntl = l+1, cntr = n - cntl;
    int lo = h[l], hi = h[l+1];
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      long long sisar = sumr - 1LL * mid * cntr;
      long long res = suml + sisar;
      long long hig = (res + cntl - 1) / cntl;
      if (hig <= mid)
        hi = mid;
      else
        lo = mid+1;
    }
    for (int i = hi; i >= max(h[l], hi-3); --i) {
      long long sisar = sumr - cntr * i;
      long long needl = cntl * i - suml;
      long long moved = min(sisar, needl);
      sisar -= moved;
      needl -= moved;
      long long cost = moved * m + sisar * r + needl * a;
      ans = min(ans, cost);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
