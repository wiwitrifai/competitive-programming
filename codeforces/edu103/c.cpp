#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  int low = 1, hig = c[0];
  long long ans = 0, cur = c[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] > b[i])
      swap(a[i], b[i]);
    long long best = b[i] - a[i] + 1;
    if (i > 1 && low != hig && a[i] != b[i] && a[i] < hig && low < b[i]) {
      best = max(best, cur - c[i-1] + abs(hig - b[i]) + abs(low - a[i]) + 2);
    }
    best += c[i];
    cur = best;
    ans = max(ans, cur);
    hig = c[i];
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
