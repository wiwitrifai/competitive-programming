#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  int ans = -1;
  for (int i = 1; i < n && ans == -1; ++i) {
    if (h[i] <= h[i-1]) continue;
    while (k > 0 && h[i-1] < h[i]) {
      int l = i-1;
      int now = h[i-1];
      while (l >= 0 && h[l] == now) --l;
      int up = h[i];
      if (l >= 0)
        up = min(up, h[l]);
      int len = i-1-l;
      if (1LL * len * (up - now) < k) {
        k -= 1LL * len * (up - now);
        for (int j = l+1; j < i; ++j) {
          h[j] = up;
        }
      } else {
        int r = (k-1) % len;
        ans = i - r;
        k = 0;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
