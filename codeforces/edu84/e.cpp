#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans(n+1, 0);
  long long sum = 0, all = 0;
  long long pw = 10;
  for (int i = n; i > 0; --i) {
    long long now = (n - i + 1) * pw % mod;
    now = (now - sum - all) % mod;
    if (now < 0)
      now += mod;
    all = (all + now) % mod;
    sum = (sum + all) % mod;
    pw = pw * 10 % mod;
    ans[i] = now;
  }
  for (int i = 1; i <= n; ++i)
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
