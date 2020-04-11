#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &a[i], &b[i]);
    }
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
      int j = (i+1) % n;
      tot += max(0LL, a[j] - b[i]);
    }
    long long ans = inf;
    for (int i = 0; i < n; ++i) {
      int j = (i+1) % n;
      ans = min(ans, tot + min(a[j], b[i]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
