#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> s(n);
  vector<long long> vis(n, 0);
  long long ans = 0, cur = 0;
  auto add_val = [&](int x, long long v) {
    if (x < n)
      vis[x] += v;
  };
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
    cur += vis[i];
    if (cur < s[i]-1) {
      long long add = s[i]-1 - cur;
      cur += add;
      add_val(i+1, -add);
      ans += add;
    }
    if (s[i] > 1) {
      add_val(i+2, +1);
      add_val(i+s[i]+1, -1);
    }
    if (cur > s[i]-1) {
      long long rest = cur - (s[i]-1);
      add_val(i+1, rest);
      add_val(i+2, -rest);
    }
  }
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
