#include <bits/stdc++.h>

using namespace std;

const int N = 55, K = 1505, mod = 1e9 + 7;

char buff[K];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  map<string, int> dp;
  for (int i = 0; i < k; ++i) {
    scanf("%s", buff);
    ++dp[buff];
  }
  for (int i = 1; i < n; ++i) {
    map<string, int> cnt;
    for (int j = 0; j < k; ++j) {
      scanf("%s", buff);
      ++cnt[buff];
    }
    map<string, int> ndp;
    for (auto & it : cnt) {
      string a = it.first.substr(0, i), b = it.first.substr(1, i);
      long long sum = dp[a];
      if (b != a)
        sum += dp[b];
      ndp[it.first] = 1LL * sum * it.second % mod;
    }
    dp.swap(ndp);
  }
  long long ans = 0;
  for (auto it : dp) {
    ans = (ans + it.second) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
