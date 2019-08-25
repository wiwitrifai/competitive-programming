#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int x[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long lo = 0, hi = 1e12;
  for (int i = 0; i < n; ++i)
    scanf("%d", x+i), lo = max(lo, (long long)x[i]);
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      if (sum + x[i] > mid) {
        sum = 0;
        ++cnt;
      }
      sum += x[i];
    }
    if (sum > 0) {
      ++cnt;
    }
    if (cnt <= m)
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%lld\n", lo);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
