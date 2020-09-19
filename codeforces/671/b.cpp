#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n;
  scanf("%lld", &n);
  long long now = 1;
  int ans = 0;
  while (n >= now * (now + 1) / 2) {
    ++ans;
    n -= now * (now + 1) / 2;
    now = now * 2 + 1;
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
