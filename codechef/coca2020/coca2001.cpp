#include <bits/stdc++.h>

using namespace std;

const int A = 1e8;

int solve() {
  int n;
  scanf("%d", &n);
  vector<int> cnt(10, 0);
  int now = 0;
  ++cnt[0];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    x /= A;
    now = (now + x) % 10;
    ans += cnt[now];
    ++cnt[now];
  }
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
