#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n), w(k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &w[i]);
    ans += a[n-1-i];
  }
  sort(w.begin(), w.end());
  reverse(w.begin(), w.end());
  int now = 0;
  int cnt = 0;
  for (int s : w) {
    if (s == 1) {
      ++cnt;
      continue;
    }
    ans += a[now];
    now += s-1;
  }
  for (int i = 0; i < cnt; ++i) {
    ans += a[n-1-i];
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
