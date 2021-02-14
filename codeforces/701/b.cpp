#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q, k;
  scanf("%d %d %d", &n, &q, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    int len = r-l + 1;
    int ans = (k - len);
    ans = ans * 2 - (a[l]-1) - (k - a[r]);
    printf("%d\n", ans);
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}

