#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 6, mod = 1e9 + 7;

char s[N];
long long dp[N];
bool ok[11];

int main() {
  int n;
  memset(dp, 0, sizeof dp);
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++)
    s[i] -= '0';
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    memset(ok, 0, sizeof ok);
    for (int j = i; j < n; j++) {
      if (ok[s[j]]) break;
      ok[s[j]] = 1;
      dp[j+1] += dp[i];
      if (dp[j+1] >= mod)
        dp[j+1] -= mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
}