#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> x(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &x[i]);
  sort(x.begin(), x.end());
  int last = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int now = x[i];
    if (last == now)
      ++now;
    if (last < now) {
      ++ans;
      last = now;
    }
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
