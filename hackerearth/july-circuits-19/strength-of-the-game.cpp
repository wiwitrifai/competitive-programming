#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, max_len = 512;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> s(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &s[i]);
  vector<int> dp(max_len, 0), tmp(max_len);
  dp[0] = 1;
  for (int x : s) {
    for (int i = 0; i < max_len; ++i) {
      tmp[i] = 0;
      for (int j = 0; j <= x; ++j) {
        tmp[i] += dp[i^j];
        if (tmp[i] >= mod)
          tmp[i] -= mod;
      }
    }
    dp.swap(tmp);
  }
  for (int i = 0; i <= m; ++i)
    printf("%d%c", dp[i], i == m ? '\n' : ' ');
  return 0;
}
