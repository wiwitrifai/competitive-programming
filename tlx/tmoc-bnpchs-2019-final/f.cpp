#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
long long a[N];


void solve() {
  long long l, r, m;
  scanf("%lld %lld %lld", &l, &r, &m);
  int n = r - l + 1;
  a[0] = 0;
  for (int i = 0; i < n; ++i)
    a[i+1] = a[i] ^ (l + i);
  int ans = 0;
  for (int le = 0; le <= min(n, 10); ++le) {
    for (int ri = n; ri >= max(le, n-10); --ri) {
      if ((a[le]^a[ri]) <= m) {
        ans = max(ans, ri-le);
      }
    }
  }
  printf("%d\n", ans);
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
