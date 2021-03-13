#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  map<string, int> cnt;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++cnt[s];
  }
  vector<vector<int>> C(n+1);
  for (int i = 0; i <= n; ++i) {
    C[i].resize(i+1);
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
      if (C[i][j] >= mod)
        C[i][j] -= mod;
    }
  }
  vector<int> dp(k + 1, 0);
  dp[0] = 1;
  for (auto& c : cnt) {
    for (int i = k; i >= 0; --i) {
      for (int take = 1; take <= c.second; ++take) {
        int p = take * (take - 1) / 2;
        if (p > i) break;
        dp[i] = (dp[i] + 1LL * dp[i-p] * C[c.second][take]) % mod;
      }
    }
  }
  printf("%d\n", dp[k]);
  return 0;
}
