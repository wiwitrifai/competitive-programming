#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void upd(long long & var, long long x) {
  var += x;
  if (var >= mod)
    var -= mod;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<long long> pre(n+1, 0);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pre[i+1] = pre[i] + a[i];
  }
  map<long long, long long> acc;
  long long all = 1;
  acc[0] = 1;
  for (int i = 0; i < n; ++i) {
    long long cur = (all - acc[pre[i]]) % mod;
    if (cur < 0)
      cur += mod;
    upd(all, cur);
    upd(acc[pre[i]], cur);
  }
  printf("%lld\n", all);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
