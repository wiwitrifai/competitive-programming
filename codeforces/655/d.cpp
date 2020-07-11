#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  long long cur = 0;
  for (int i = 0; i < n; i += 2)
    cur += a[i];
  long long ans = cur;
  int now = n-1;
  for (int i = 0; i < n; ++i) {
    cur -= a[now];
    cur += a[(now + n - 1) % n];
    now = (now - 2) % n;
    if (now < 0)
      now += n;
    ans = max(ans, cur);
  }
  printf("%lld\n", ans);
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
