#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  long long u, v;
  scanf("%d %lld %lld", &n, &u, &v);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  bool wall = 1;
  for (int i = 0; i < n-1; ++i) {
    wall &= abs(a[i] - a[i+1]) <= 1;
  }
  int low = *min_element(a.begin(), a.end());
  int hig = *max_element(a.begin(), a.end());
  long long ans = v + min(u, v);
  if (low != hig) {
    ans = min(ans, u);
    ans = min(ans, v);
  }
  if (!wall)
    ans = 0;
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
