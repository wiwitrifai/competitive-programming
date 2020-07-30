#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k, z;
  scanf("%d %d %d", &n, &k, &z);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0, cur = 0;
  int sisa = k - min(k / 2, z) * 2;
  for (int i = 0; i <= sisa; ++i)
    cur += a[i];
  int maxi = 0;
  for (int i = 0; i + 1 < n && i <= sisa; ++i) {
    maxi = max(maxi, a[i]+a[i+1]);
  }
  int cnt = (k - sisa) / 2;
  ans = cur + maxi * cnt;
  while (cnt > 0) {
    cur += a[++sisa];
    if (sisa + 1 < n)
      maxi = max(maxi, a[sisa] + a[sisa + 1]);
    cur += a[++sisa];
    if (sisa + 1 < n)
      maxi = max(maxi, a[sisa] + a[sisa + 1]);
    --cnt;
    ans = max(ans, cur + maxi * cnt);
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
